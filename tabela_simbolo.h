#ifndef TABELA_SIMBOLO
#define TABELA_SIMBOLO
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "valor_lexico.h"

// Estrutura para um nó da lista encadeada
typedef struct NodoTabela {
    VALOR_LEXICO* info;           // Valor armazenado no nó
    struct NodoTabela* proximo;  // Ponteiro para o próximo nó
} NodoTabela;

// Estrutura para a lista encadeada
typedef struct Tabela {
    NodoTabela* primeiro;  // Ponteiro para o início da lista
} Tabela;

Tabela* criaTabela();
void insereValorLexicoNaTabela (Tabela* tabela, VALOR_LEXICO* valor_lexico);
void destroiTabela(Tabela* tabela);
NodoTabela* criarNodoTabela(VALOR_LEXICO* valor_lexico);
void imprimeTabela(Tabela *tabela);

#endif