#ifndef PILHA_TABELAS_H
#define PILHA_TABELAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolo.h"
#include "valor_lexico.h"
// Códigos de erro
#define ERR_UNDECLARED 10
#define ERR_DECLARED 11 
#define ERR_VARIABLE 20 
#define ERR_FUNCTION 21


// Estrutura da pilha de tabelas de símbolos
typedef struct PilhaTabelaSimbolos {
    TabelaSimbolos *topo;
    TabelaSimbolos **tabelas;
} PilhaTabelaSimbolos;

typedef struct AST {
    char* tipo;
    struct AST* filhoEsquerdo;
    struct AST* filhoDireito;
} AST;

PilhaTabelaSimbolos* criarPilha();
void empilhar(PilhaTabelaSimbolos* pilha, TabelaSimbolos* tabela);
void desempilhar(PilhaTabelaSimbolos* pilha);

TabelaSimbolos* obterTabelaAtual(PilhaTabelaSimbolos* pilha);

void verificarDeclaracao(PilhaTabelaSimbolos* pilha, char* lexema);

void declararIdentificador(PilhaTabelaSimbolos* pilha, char* lexema, EntradaTabelaSimbolos entrada, int linha);

void verificarUsoIdentificador(PilhaTabelaSimbolos* pilha, char* lexema, int linha, int naturezaEsperada);

char* inferirTipo(AST* no, PilhaTabelaSimbolos* pilha);
void limparPilha(PilhaTabelaSimbolos* pilha);
#endif
