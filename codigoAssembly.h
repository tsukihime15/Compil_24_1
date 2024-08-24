#ifndef CODASSEMBLY_H
#define CODASSEMBLY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

/*Arquitetura x86-64*/
#define MAX_REG 8;

extern int Registrador_atual;
extern int section_bss;
extern int section_text_var_glbl;
extern int section_text_func;
extern int num_var_local;

void generateAsm(NODO* arvore);
void geraCodigoPelaAST(NODO* arvore, FILE* output_file);
void geraCodigoVarGlobal(NODO* arvore, FILE* output_file);
void geraCodigoVariable(NODO* nodo, FILE* output_file);
void geraCodigoAtrib(NODO* arvore, FILE *output_file);
void geraCodigoOperacao(NODO* arvore, FILE *output_file);
void geraCodigoControle(NODO* arvore, FILE *output_file);
void geraCodigoRetorno(NODO* arvore, FILE *output_file);
void geraCodigoChamadaFuncao(NODO* arvore, FILE *output_file);
void geraCodigoFuncao(NODO* nodo, FILE *output_file);
void geraCodigoExpressao(NODO *arvore, FILE *output_file);

int selecionaRegistrador (int Registrador_atual);
int contador_de_argumentos(NODO* nodo);
void printNodos(NODO *nodo, FILE *output_file);

#endif
