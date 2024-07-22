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
    union {
        int int_val;
        float float_val;
        char* string_val;
    } valor;
} EntradaTabelaSimbolos;

typedef struct Simbolo {
    char* lexema;
    EntradaTabelaSimbolos entrada;
    struct Simbolo* proximo;
} Simbolo;

typedef struct {
    Simbolo* primeiro;
} TabelaSimbolos;

void criaTabelaMain(TabelaSimbolos* entrada);

TabelaSimbolos* criarTabelaSimbolos();
Simbolo* criarSimbolo(const char* lexema, EntradaTabelaSimbolos entrada);
EntradaTabelaSimbolos* criaEntradaTabelaSimbolos(VALOR_LEXICO valor_lexico);
void inserirSimbolo(TabelaSimbolos* tabela, const char* lexema, EntradaTabelaSimbolos entrada);
Simbolo* buscarSimbolo(TabelaSimbolos* tabela, const char* lexema);
void liberarTabelaSimbolos(TabelaSimbolos* tabela);
#endif
