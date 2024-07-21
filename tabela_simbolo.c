#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolo.h"

// Função para criar uma nova tabela de símbolos
TabelaSimbolos* criarTabelaSimbolos() {
    TabelaSimbolos* tabela = (TabelaSimbolos*)malloc(sizeof(TabelaSimbolos));
    tabela->primeiro = NULL;
    return tabela;
}

// Função para criar uma nova entrada na tabela de símbolos
Simbolo* criarSimbolo(const char* lexema, EntradaTabelaSimbolos entrada) {
    Simbolo* simbolo = (Simbolo*)malloc(sizeof(Simbolo));
    simbolo->lexema = strdup(lexema);
    simbolo->entrada = entrada;
    simbolo->proximo = NULL;
    return simbolo;
}

// Função para inserir uma nova entrada na tabela de símbolos
void inserirSimbolo(TabelaSimbolos* tabela, const char* lexema, EntradaTabelaSimbolos entrada) {
    Simbolo* simbolo = criarSimbolo(lexema, entrada);
    simbolo->proximo = tabela->primeiro;
    tabela->primeiro = simbolo;
}

// Função para buscar um símbolo na tabela de símbolos
Simbolo* buscarSimbolo(TabelaSimbolos* tabela, const char* lexema) {
    Simbolo* atual = tabela->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->lexema, lexema) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para liberar a memória da tabela de símbolos
void liberarTabelaSimbolos(TabelaSimbolos* tabela) {
    Simbolo* atual = tabela->primeiro;
    while (atual != NULL) {
        Simbolo* proximo = atual->proximo;
        free(atual->lexema);
        free(atual);
        atual = proximo;
    }
    free(tabela);
}

