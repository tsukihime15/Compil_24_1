#ifndef TABELA_SIMBOLO
#define TABELA_SIMBOLO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "valor_lexico.h"

#define FUNCAO 1
#define IDENTIFICADOR 2

typedef struct {
    int linha;
    int natureza;
    char* tipo;
    struct EntradaTabelaSimbolos *proximo;
} EntradaTabelaSimbolos;

typedef struct Simbolo {
    char* lexema;
    EntradaTabelaSimbolos *entrada;
} Simbolo;

typedef struct {
    Simbolo **simbolos;
    struct TabelaSimbolos* pai;
    struct TabelaSimbolos* proximo;
} TabelaSimbolos;


TabelaSimbolos* criarTabelaSimbolos();
Simbolo* criarSimbolo(char* lexema, EntradaTabelaSimbolos entrada);
EntradaTabelaSimbolos* criaEntradaTabelaSimbolos(VALOR_LEXICO valor_lexico);
void inserirSimbolo(TabelaSimbolos* tabela,char* lexema, EntradaTabelaSimbolos entrada);
Simbolo* buscarSimbolo(TabelaSimbolos* tabela, char* lexema);
void liberarTabelaSimbolos(TabelaSimbolos* tabela);
#endif
