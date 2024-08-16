#ifndef PILHA_TABELA_H
#define PILHA_TABELA_H

#include "tabela_simbolo.h"
#include "arvore.h"

// Códigos de erro
#define ERR_UNDECLARED 10
#define ERR_DECLARED 11 
#define ERR_VARIABLE 20 
#define ERR_FUNCTION 21

// Estrutura para um nó da pilha de listas encadeadas
typedef struct NodoPilha {
    Tabela* tabela; // Ponteiro para a lista encadeada
    struct NodoPilha* proximo; // Ponteiro para o próximo nó da pilha
} NodoPilha;

// Estrutura para a pilha de listas encadeadas
typedef struct Pilha_tabelas {
    NodoPilha* topo;  // Ponteiro para o topo da pilha
} Pilha_tabelas;


Pilha_tabelas* criaPilha ();
Tabela* topoPilha(Pilha_tabelas* pilha);
NodoPilha* criarNodoPilha(Tabela* tabela);
void insereValorLexicoNoTopoDaPilha(Pilha_tabelas* Pilha_tabelas, VALOR_LEXICO* valor_lexico);
void popTabelaNaPilha(Pilha_tabelas *Pilha);
void pushTabelaNaPilha(Pilha_tabelas* Pilha, Tabela *nova_tabela);

void destroiListaTabelas(Pilha_tabelas* pilha);
void imprimeUltimaTabelaDaPilha(Pilha_tabelas* Pilha_tabelas);

void verificaERR_UNDECLARED_FUNCTION(Pilha_tabelas *Pilha_tabelas, VALOR_LEXICO* identificador);
void verificaERR_DECLARED(Pilha_tabelas *Pilha_tabelas, VALOR_LEXICO* identificador);
void verificaERR_VARIABLE_UNDECLARED_chamadafuncao(Pilha_tabelas *Pilha_tabelas, char *valor_token, int linha_token);

void imprimeTabela(Tabela *tabela);
void imprimeUltimaTabelaDaPilha(Pilha_tabelas* pilha);

int infereTipo(int tipo1, int tipo2);
int infereTipoExpressao(NODO *raiz);
int verificaTipo(char *tipo);
int obtemTipo(Pilha_tabelas *Pilha_tabelas, VALOR_LEXICO* identificador);
void concatenate_list(NODO* list1, NODO* list2);
#endif
