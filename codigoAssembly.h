#ifndef CODASSEMBLY_H
#define CODASSEMBLY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

/*Arquitetura x86-64*/
#define MAX_REG = 8;

typedef struct {
    char *nome;         // Nome da função
    int cont_var_local; // Contador de variáveis locais
} INFO_FUNC;

extern int Registrador_atual;

void generateAsm(NODO* arvore);
void geraCodigoPelaAST(NODO* arvore, FILE* output_file);
void geraCodigoAtrib(NODO* arvore, FILE *output_file);
void geraCodigoOperacao(NODO* arvore, FILE *output_file);
void geraCodigoControle(NODO* arvore, FILE *output_file);
void geraCodigoChamadaFuncao(NODO* arvore, FILE *output_file);
void geraCodigoFuncao(NODO* nodo, FILE *output_file);
void geraCodigoExpressao(NODO *arvore, FILE *output_file);
void geraCodigoBloco(NODO *arvore, FILE *output_file);

int selecionaRegistrador (int Registrador_atual);

#endif
