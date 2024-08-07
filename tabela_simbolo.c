#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolo.h"
#include "valor_lexico.h"

/* Recebe uma tabela de simbolos e uma entrada, e insere as informacoes da entrada na tabela. */
void insereEntradaTabela(Tabela** tabela, VALOR_LEXICO* valor_lexico)
{
    Tabela* novo = (Tabela*)malloc(sizeof(Tabela));
    novo->info = (VALOR_LEXICO*)malloc(sizeof(VALOR_LEXICO));

    novo->info->valor = strdup(valor_lexico->valor);
    novo->info->num_linha = valor_lexico->num_linha;
    novo->info->natureza = valor_lexico->natureza;
    novo->info->tipo = valor_lexico->tipo;

    novo->proximo = NULL;

    if (*tabela == NULL)
        *tabela = novo;
    else
    {
        Tabela* atual = *tabela;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
    }
}

/* Recebe uma lista de tabela de simbolos e uma entrada, e insere a entrada na ultima tabela de simbolos da lista. */
void insereUltimaTabela(Lista_tabelas** lista_tabelas, VALOR_LEXICO* valor_lexico) 
{   
    if (*lista_tabelas == NULL || valor_lexico == NULL) {
        return;
    }
    
    Lista_tabelas* atual = *lista_tabelas;
    
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    
   insereEntradaTabela(&(atual->tabela_simbolos), valor_lexico);
}

/* Insere uma nova tabela de simbolos na lista de tabela de simbolos. */
void pushTabela(Lista_tabelas **lista, Tabela *nova_tabela)
{
    //printf("EMPILHOU\n");
    
    Lista_tabelas* novo = (Lista_tabelas*)malloc(sizeof(Lista_tabelas));
    novo->tabela_simbolos = nova_tabela;
    novo->proximo = NULL;

    if (*lista == NULL)
    {
        novo->anterior = NULL;
        *lista = novo;
    }

    else
    {
        Lista_tabelas* atual = *lista;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
        novo->anterior = atual;
    }
}

/* Remove a ultima tabela de simbolos que foi adicionada na lista de tabela de simbolos. */
void popTabela(Lista_tabelas **lista_tabelas)
{
    //printf("DESEMPILHOU\n");
    
    if (*lista_tabelas == NULL) 
        return;
    
    Lista_tabelas* atual = *lista_tabelas;
    
    while (atual->proximo != NULL)
        atual = atual->proximo;
    
    if (atual->anterior == NULL) 
        *lista_tabelas = NULL;
        
    else 
        atual->anterior->proximo = NULL;
    
    destroiTabela(&(atual->tabela_simbolos));
    free(atual);
}

/* Destroi uma tabela de simbolos, liberando o espaco de memoria referente a ela. */
void destroiTabela(Tabela** tabela) 
{
    Tabela* atual = *tabela;
    Tabela* proximo;

    while (atual != NULL) 
    {
        proximo = atual->proximo;
        free(atual->info->valor);
        free(atual->info);
        free(atual);
        atual = proximo;
    }

    *tabela = NULL;
}

/* Destroi todas as tabelas de simbolos de uma lista de tabelas de simbolos. */
void destroiListaTabelas(Lista_tabelas** lista_tabelas) 
{
    Lista_tabelas* atual = *lista_tabelas;
    Lista_tabelas* proximo;

    while (atual != NULL) 
    {
        proximo = atual->proximo;
        destroiTabela(&(atual->tabela_simbolos));
        free(atual);
        atual = proximo;
    }

    *lista_tabelas = NULL;
}

/* Verifica os seguintes erros de semantica:
ERR_UNDECLARED - Caso o identificador não tenha sido declarado no seu uso;
ERR_FUNCTION   - Caso o identificador dito como funcao esteja sendo usado como variavel. */
void verificaERR_UNDECLARED_FUNCTION(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador)
{
    Lista_tabelas *lista_atual = lista_tabelas;
    int achou_funcao = 0;

    while (lista_atual != NULL)
    {
	Tabela *tabela_atual = lista_atual->tabela_simbolos;

	while (tabela_atual != NULL)
	{
	    if (strcmp(identificador->valor, tabela_atual->info->valor) == 0)
	    {
	    	if (tabela_atual->info->natureza == FUNCTION)
			achou_funcao = 1;
	    	
	    	else if (tabela_atual->info->natureza == VARIABLE)
			return;	
	    }
	        
	    tabela_atual = tabela_atual->proximo;
	}

	lista_atual = lista_atual->proximo;
    }
    
    if (achou_funcao == 1)
    {
	printf("ERRO DE SEMANTICA - LINHA %d - FUNCAO '%s' SENDO USADA COMO VARIAVEL\n", identificador->num_linha, identificador->valor);
	exit(ERR_FUNCTION);   
    }
    
    else
    {
	printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", identificador->num_linha, identificador->valor);
	exit(ERR_UNDECLARED);   
    }
}

/* Verifica os seguintes erros de semantica, nos casos de uma chama de funcao no codigo sendo analisado:
ERR_VARIABLE   - Caso o identificador dito como variavel esteja sendo usado como funcao.
ERR_UNDECLARED - Caso o identificador não tenha sido declarado no seu uso; */
void verificaERR_VARIABLE_UNDECLARED_chamadafuncao(Lista_tabelas *lista_tabelas, char *valor, int num_linha)
{
	Lista_tabelas *lista_atual = lista_tabelas;

	while (lista_atual != NULL)
	{
        	Tabela *tabela_atual = lista_atual->tabela_simbolos;

		while (tabela_atual != NULL)
		{
		    if (strcmp(valor, tabela_atual->info->valor) == 0)
		    {
		   	if (tabela_atual->info->natureza != FUNCTION)
		   	{
		   		printf("ERRO DE SEMANTICA - LINHA %d - VARIAVEL '%s' SENDO USADA COMO FUNCAO\n", num_linha, valor);
		   		exit(ERR_VARIABLE);
		   	}     	
		    }
		        
		    tabela_atual = tabela_atual->proximo;
		}

        	lista_atual = lista_atual->proximo;
    	}
    
	printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", num_linha, valor);
	exit(ERR_UNDECLARED);	
}

/* Verifica o seguinte erro de semantica:
ERR_DECLARED - Nos casos em que um identificador ja declarado esteja sendo redeclarado. */
void verificaERR_DECLARED(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador)
{
	Lista_tabelas *lista_atual = lista_tabelas;
	
	if (identificador->natureza != FUNCTION)
		while (lista_atual->proximo != NULL)
			lista_atual = lista_atual->proximo;

	Tabela *tabela_atual;
	tabela_atual = lista_atual->tabela_simbolos;

	while (tabela_atual != NULL)
	{

		if (strcmp(identificador->valor, tabela_atual->info->valor) == 0)
		{
			printf("ERRO DE SEMANTICA - LINHA %d - REDECLARACAO DO IDENTIFICADOR '%s'\n", identificador->num_linha
    , identificador->valor);
			exit(ERR_DECLARED);
		}

		tabela_atual = tabela_atual->proximo;
	}

	return;
}

/* Recebe uma tabela de simbolos, e imprime cada simbolo com suas caracteristicas. */
void imprimeTabela(Tabela *tabela)
{
	Tabela* atual = tabela;

	while (atual != NULL) 
	{
		printf("VALOR: %s\n", atual->info->valor);
		printf("TIPO: %d\n", atual->info->tipo);
		printf("NATUREZA: %d\n", atual->info->natureza);
		printf("LINHA: %d\n", atual->info->num_linha);

		atual = atual->proximo;
	}
}

/* Recebe uma lista de tabelas de simbolos, e imprime a ultima tabela inserida na lista. */
void imprimeUltimaTabela(Lista_tabelas *lista_tabelas)
{
	Lista_tabelas *atual = lista_tabelas;
    	while (atual->proximo != NULL)
        	atual = atual->proximo;
	printf("TABELA LOCAL:\n\n");
        imprimeTabela(atual->tabela_simbolos);
	printf("------------------\n");
}

/* Recebe dois inteiros representando um tipo de duas variaveis envolvidas em uma operacao,
e infere qual sera o tipo do resultado da operacao. */
int infereTipo(int tipo1, int tipo2)
{
	if (tipo1 == FLOAT || tipo2 == FLOAT)
	{
		//printf("INFERIU FLOAT\n");
		return FLOAT;
	}
		
	else if (tipo1 == INT || tipo2 == INT)
	{
		//printf("INFERIU INT\n");
		return INT;
	}
	
	else if (tipo1 == BOOL || tipo2 == BOOL)
	{
		//printf("INFERIU BOOL\n");
		return BOOL;
	}
	
	else
		return -1;	
}

/* Recebe um NODO raiz de uma expressao, e decide qual sera o tipo do NODO, a partir
da inferencia de tipos aplicada na expressao. */
int infereTipoExpressao(NODO *raiz) 
{
    int tipo_encontrado = -1;
    
    if (raiz != NULL) 
    {
        tipo_encontrado = infereTipo(raiz->filho->valor_lexico->tipo,raiz->filho->irmao->valor_lexico->tipo);
    }
    
    return tipo_encontrado;
}

/* Recebe uma string representando um tipo, e retorna o valor inteiro que
corresponde a esse tipo. */
int verificaTipo(char *tipo)
{
	if (strcmp(tipo,"int") == 0)
		return INT;
	else if (strcmp(tipo,"float") == 0)
		return FLOAT;
	else if (strcmp(tipo,"bool") == 0)
		return BOOL;
	else
		return -1;
}

/* Recebe um identificador, e obtem seu tipo, que esta informado na ultima tabela de simbolos inserida. */
int obtemTipo(Lista_tabelas *lista_tabelas, VALOR_LEXICO* identificador)
{
    Lista_tabelas *lista_atual = lista_tabelas;
    int tipo_atual = -1;

    while (lista_atual != NULL)
    {
        Tabela *tabela_atual = lista_atual->tabela_simbolos;

        while (tabela_atual != NULL)
        {
            if (strcmp(identificador->valor, tabela_atual->info->valor) == 0)
		tipo_atual = tabela_atual->info->tipo; 
            tabela_atual = tabela_atual->proximo;
        }

        lista_atual = lista_atual->proximo;
    }
    
    return tipo_atual;	
}

/* Recebe duas listas de nos da AST, e concatena as duas. 
void concatenate_list(NODO* list1, NODO* list2)
{
    NODO* last_node_from_list = get_last_valid_node_from_list(list1);
    adicionaNODO(last_node_from_list, list2);
}*/