#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolo.h"
#include "valor_lexico.h"

/* Recebe uma tabela de simbolos e uma entrada, e insere as informacoes da entrada na tabela. */
void insereEntradaTabela(Tabela** tabela, ValorLexico* valor_lexico)
{
    Tabela* novo = (Tabela*)malloc(sizeof(Tabela));
    novo->info = (ValorLexico*)malloc(sizeof(ValorLexico));

    novo->info->valor_token = strdup(valor_lexico->valor_token);
    novo->info->linha_token = valor_lexico->linha_token;
    novo->info->natureza_token = valor_lexico->natureza_token;
    novo->info->tipo_token = valor_lexico->tipo_token;
    novo->info->tamanho_token = valor_lexico->tamanho_token;

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
void insereUltimaTabela(Lista_tabelas** lista_tabelas, ValorLexico* valor_lexico) 
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
        free(atual->info->valor_token);
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
void verificaERR_UNDECLARED_FUNCTION(Lista_tabelas *lista_tabelas, ValorLexico* identificador)
{
    Lista_tabelas *lista_atual = lista_tabelas;
    int achou_funcao = 0;

    while (lista_atual != NULL)
    {
	Tabela *tabela_atual = lista_atual->tabela_simbolos;

	while (tabela_atual != NULL)
	{
	    if (strcmp(identificador->valor_token, tabela_atual->info->valor_token) == 0)
	    {
	    	if (tabela_atual->info->natureza_token == FUNCTION)
			achou_funcao = 1;
	    	
	    	else if (tabela_atual->info->natureza_token == VARIABLE)
			return;	
	    }
	        
	    tabela_atual = tabela_atual->proximo;
	}

	lista_atual = lista_atual->proximo;
    }
    
    if (achou_funcao == 1)
    {
	printf("ERRO DE SEMANTICA - LINHA %d - FUNCAO '%s' SENDO USADA COMO VARIAVEL\n", identificador->linha_token, identificador->valor_token);
	exit(ERR_FUNCTION);   
    }
    
    else
    {
	printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", identificador->linha_token, identificador->valor_token);
	exit(ERR_UNDECLARED);   
    }
}

/* Verifica os seguintes erros de semantica, nos casos de uma chama de funcao no codigo sendo analisado:
ERR_VARIABLE   - Caso o identificador dito como variavel esteja sendo usado como funcao.
ERR_UNDECLARED - Caso o identificador não tenha sido declarado no seu uso; */
void verificaERR_VARIABLE_UNDECLARED_chamadafuncao(Lista_tabelas *lista_tabelas, char *valor_token, int linha_token)
{
	Lista_tabelas *lista_atual = lista_tabelas;

	while (lista_atual != NULL)
	{
        	Tabela *tabela_atual = lista_atual->tabela_simbolos;

		while (tabela_atual != NULL)
		{
		    if (strcmp(valor_token, tabela_atual->info->valor_token) == 0)
		    {
		   	if (tabela_atual->info->natureza_token != FUNCTION)
		   	{
		   		printf("ERRO DE SEMANTICA - LINHA %d - VARIAVEL '%s' SENDO USADA COMO FUNCAO\n", linha_token, valor_token);
		   		exit(ERR_VARIABLE);
		   	}     	
		    }
		        
		    tabela_atual = tabela_atual->proximo;
		}

        	lista_atual = lista_atual->proximo;
    	}
    
	printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", linha_token, valor_token);
	exit(ERR_UNDECLARED);	
}

/* Verifica o seguinte erro de semantica:
ERR_DECLARED - Nos casos em que um identificador ja declarado esteja sendo redeclarado. */
void verificaERR_DECLARED(Lista_tabelas *lista_tabelas, ValorLexico* identificador)
{
	Lista_tabelas *lista_atual = lista_tabelas;
	
	if (identificador->natureza_token != FUNCTION)
		while (lista_atual->proximo != NULL)
			lista_atual = lista_atual->proximo;

	Tabela *tabela_atual;
	tabela_atual = lista_atual->tabela_simbolos;

	while (tabela_atual != NULL)
	{

		if (strcmp(identificador->valor_token, tabela_atual->info->valor_token) == 0)
		{
			printf("ERRO DE SEMANTICA - LINHA %d - REDECLARACAO DO IDENTIFICADOR '%s'\n", identificador->linha_token, identificador->valor_token);
			exit(ERR_DECLARED);
		}

		tabela_atual = tabela_atual->proximo;
	}

	return;
}

/* Recebe um valor inteiro referente a um tipo, e retorna uma string indicando o tipo. */
char* obtemNomeTipo (int valor_tipo)
{
	char* nome_tipo = calloc(MAXIMO_CARACTERES_TIPO, sizeof(char));
	if (valor_tipo == INT)
		strcpy(nome_tipo,"int");
	else if (valor_tipo == FLOAT)
		strcpy(nome_tipo,"float");
	else if (valor_tipo == BOOL)
		strcpy(nome_tipo,"bool");
	return nome_tipo;
}

/* Recebe uma string qualificando uma chamada de funcao com "call " concatenado, e obtem o nome da funcao sendo chamada. */
char* obtemNomeFuncao(char* nomeChamadaFuncao)
{
	char *nomeFuncao = calloc(MAXIMO_CARACTERES_NOME,sizeof(char));
	strcpy(nomeFuncao,nomeChamadaFuncao+5);
	return nomeFuncao;
}

/* Recebe uma tabela de simbolos, e imprime cada simbolo com suas caracteristicas. */
void imprimeTabela(Tabela *tabela)
{
	Tabela* atual = tabela;

	while (atual != NULL) 
	{
		printf("VALOR: %s\n", atual->info->valor_token);
		printf("TIPO: %s\n", obtemNomeTipo(atual->info->tipo_token));
		printf("NATUREZA: %d\n", atual->info->natureza_token);
		printf("LINHA: %d\n", atual->info->linha_token);
		printf("TAMANHO: %d\n\n", atual->info->tamanho_token);
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

/* Recebe um nodo raiz de uma expressao, e decide qual sera o tipo do nodo, a partir
da inferencia de tipos aplicada na expressao. */
int infereTipoExpressao(Nodo *raiz) 
{
    int tipo_encontrado = -1;
    
    if (raiz != NULL) 
    {
        //printf("ACHOU %d\n", raiz->info->tipo_token);
        
        // Atualiza o tipo encontrado com o tipo do nodo atual
        tipo_encontrado = raiz->info->tipo_token;
        
        for (int i = 0; i < raiz->numeroFilhos; i++) 
            tipo_encontrado = infereTipo(tipo_encontrado, infereTipoExpressao(raiz->filho[i]));
    }
    
    return tipo_encontrado;
}

/* Recebe uma string representando um tipo, e retorna o valor inteiro que
corresponde a esse tipo. */
int verificaTipo(char *tipo_token)
{
	if (strcmp(tipo_token,"int") == 0)
		return INT;
	else if (strcmp(tipo_token,"float") == 0)
		return FLOAT;
	else if (strcmp(tipo_token,"bool") == 0)
		return BOOL;
	else
		return -1;
}

/* Recebe um identificador, e obtem seu tipo, que esta informado na ultima tabela de simbolos inserida. */
int obtemTipo(Lista_tabelas *lista_tabelas, ValorLexico* identificador)
{
    Lista_tabelas *lista_atual = lista_tabelas;
    int tipo_atual = -1;

    while (lista_atual != NULL)
    {
        Tabela *tabela_atual = lista_atual->tabela_simbolos;

        while (tabela_atual != NULL)
        {
            if (strcmp(identificador->valor_token, tabela_atual->info->valor_token) == 0)
		tipo_atual = tabela_atual->info->tipo_token; 
            tabela_atual = tabela_atual->proximo;
        }

        lista_atual = lista_atual->proximo;
    }
    
    return tipo_atual;	
}

/* Recebe duas listas de nos da AST, e concatena as duas. */
void concatenate_list(Nodo* list1, Nodo* list2)
{
    Nodo* last_node_from_list = get_last_valid_node_from_list(list1);
    adicionaNodo(last_node_from_list, list2);
}