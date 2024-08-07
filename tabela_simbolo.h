#ifndef TABELA_SIMBOLO
#define TABELA_SIMBOLO

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "valor_lexico.h"
#include "arvore.h"

// Códigos de erro
#define ERR_UNDECLARED 10
#define ERR_DECLARED 11 
#define ERR_VARIABLE 20 
#define ERR_FUNCTION 21

typedef struct tabela
{
	VALOR_LEXICO *info;
	struct tabela *proximo;

} Tabela;

typedef struct lista_tabelas
{
	struct lista_tabelas *proximo;
	struct lista_tabelas *anterior;
	Tabela *tabela_simbolos;

} Lista_tabelas;

void insereEntradaTabela (Tabela** tabela, VALOR_LEXICO* valor_lexico);
void insereUltimaTabela(Lista_tabelas** lista_tabelas, VALOR_LEXICO* valor_lexico);
void popTabela(Lista_tabelas **lista);
void pushTabela(Lista_tabelas** lista, Tabela *nova_tabela);
void destroiTabela(Tabela** tabela);
void destroiListaTabelas(Lista_tabelas** lista_tabelas);
void imprimeTabela(Tabela *tabela);
void imprimeUltimaTabela(Lista_tabelas* lista_tabelas);

void verificaERR_UNDECLARED_FUNCTION(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador);
void verificaERR_DECLARED(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador);
void verificaERR_VARIABLE_UNDECLARED_chamadafuncao(Lista_tabelas *lista_tabelas, char *valor_token, int linha_token);
int infereTipo(int tipo1, int tipo2);
int infereTipoExpressao(NODO *raiz);
int verificaTipo(char *tipo);
int obtemTipo(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador);
#endif
