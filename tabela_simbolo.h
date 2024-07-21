#ifndef TABELA_SIMBOLO
#define TABELA_SIMBOLO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
    IDENTIFICADOR,
    FUNCAO
} Natureza;

typedef struct {
    int linha;
    Natureza natureza;
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


TabelaSimbolos* criarTabelaSimbolos();
Simbolo* criarSimbolo(const char* lexema, EntradaTabelaSimbolos entrada);
void inserirSimbolo(TabelaSimbolos* tabela, const char* lexema, EntradaTabelaSimbolos entrada);
Simbolo* buscarSimbolo(TabelaSimbolos* tabela, const char* lexema);
void liberarTabelaSimbolos(TabelaSimbolos* tabela);
#endif
