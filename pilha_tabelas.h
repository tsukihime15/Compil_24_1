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
    TabelaSimbolos* tabela;
    struct PilhaTabelaSimbolos* proximo;
} PilhaTabelaSimbolos;

typedef struct AST {
    char* tipo;
    struct AST* filhoEsquerdo;
    struct AST* filhoDireito;
} AST;

PilhaTabelaSimbolos* criarPilha();
EntradaTabelaSimbolos* criaEntradaTabelaSimbolos(VALOR_LEXICO valor_lexico);
void empilhar(PilhaTabelaSimbolos** pilha, TabelaSimbolos* tabela);
void desempilhar(PilhaTabelaSimbolos** pilha);
TabelaSimbolos* obterTabelaAtual(PilhaTabelaSimbolos* pilha);
void verificarDeclaracao(PilhaTabelaSimbolos* pilha, const char* lexema, int linha);
void declararIdentificador(PilhaTabelaSimbolos* pilha, const char* lexema, EntradaTabelaSimbolos entrada, int linha);
void verificarUsoIdentificador(PilhaTabelaSimbolos* pilha, const char* lexema, int linha, Natureza naturezaEsperada);
char* inferirTipo(AST* no, PilhaTabelaSimbolos* pilha);

#endif