#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include "valor_lexico.h"

typedef struct NODO
{
    VALOR_LEXICO valor_lexico;
    struct NODO* pai;
    struct NODO* irmao;
    struct NODO* filho;
} NODO;

NODO* createNodo(VALOR_LEXICO valor_lexico);
NODO* createNodoToFunctionCall(VALOR_LEXICO valor_lexico);
void addFilho(NODO* pai, NODO* filho);
NODO* getUltimoFilho(NODO* pai);
void removeNodo(NODO* node);
void exporta(NODO* node);
void printValorLexico(NODO* node);
void printArvore(NODO* node);

#endif