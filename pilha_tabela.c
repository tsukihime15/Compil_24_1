#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha_tabela.h"

/*Cria uma Pilha*/
Pilha_tabelas* criaPilha ()
{
    Pilha_tabelas* pilha = (Pilha_tabelas*) malloc (sizeof(Pilha_tabelas));
    pilha->topo = NULL;
    return pilha;
} 

/*Retorna a tabela no topo da Pilha*/
Tabela* topoPilha(Pilha_tabelas* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return NULL;
    }

    return pilha->topo->tabela;
}

// Função para criar um novo nó da pilha
NodoPilha* criarNodoPilha(Tabela* tabela) {
    NodoPilha* novo = (NodoPilha*)malloc(sizeof(NodoPilha));
    if (novo == NULL) {
        printf("Falha ao alocar memória\n");
    }
    novo->tabela = tabela;
    novo->proximo = NULL;
    return novo;
}

/* Recebe uma lista de tabela de simbolos e uma entrada, e insere a entrada na ultima tabela de simbolos da lista. */
void insereValorLexicoNoTopoDaPilha(Pilha_tabelas* pilha, VALOR_LEXICO* valor_lexico) 
{   
    if (pilha == NULL || valor_lexico == NULL) {
        return;
    }

    Tabela* tabelaTopo = topoPilha(pilha);
    if (tabelaTopo != NULL) {
        insereValorLexicoNaTabela(tabelaTopo, valor_lexico);
    } else {
        printf("Pilha está vazia\n");
    }
}

// Adiciona uma tabela na pilha
void pushTabelaNaPilha(Pilha_tabelas* pilha, Tabela* tabela) {
    NodoPilha* novoNodoPilha = criarNodoPilha(tabela);
    novoNodoPilha->proximo = pilha->topo;
    pilha->topo = novoNodoPilha;
}
// Remove a última tabela da pilha
void popTabelaNaPilha(Pilha_tabelas* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    }

    NodoPilha* temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    destroiTabela(temp->tabela); // Destroi a tabela
    free(temp);
}

// Destroi todas as tabelas na pilha
void destroiListaTabelas(Pilha_tabelas* pilha) {
    while (pilha->topo != NULL) {
        popTabelaNaPilha(pilha);
    }
}

/* Verifica os seguintes erros de semantica:
ERR_UNDECLARED - Caso o identificador não tenha sido declarado no seu uso;
ERR_FUNCTION   - Caso o identificador dito como funcao esteja sendo usado como variavel. */
void verificaERR_UNDECLARED_FUNCTION(Pilha_tabelas *pilha, VALOR_LEXICO* identificador)
{
 NodoPilha* lista_atual = pilha->topo;
    int achou_funcao = 0;

    while (lista_atual != NULL) {
        Tabela* tabela_atual = lista_atual->tabela;
        NodoTabela* nodo_tabela_atual = tabela_atual->primeiro;

        while (nodo_tabela_atual != NULL) {
            if (strcmp(identificador->valor, nodo_tabela_atual->info->valor) == 0) {
                if (nodo_tabela_atual->info->natureza == FUNCTION) {
                    achou_funcao = 1;
                } else if (nodo_tabela_atual->info->natureza == VARIABLE) {
                    return;
                }
            }
            nodo_tabela_atual = nodo_tabela_atual->proximo;
        }
        lista_atual = lista_atual->proximo;
    }

    if (achou_funcao == 1) {
        printf("ERRO DE SEMANTICA - LINHA %d - FUNCAO '%s' SENDO USADA COMO VARIAVEL\n", identificador->num_linha, identificador->valor);
        exit(ERR_FUNCTION);   
    } else {
        printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", identificador->num_linha, identificador->valor);
        exit(ERR_UNDECLARED);   
    }
}

/* Verifica os seguintes erros de semantica, nos casos de uma chama de funcao no codigo sendo analisado:
ERR_VARIABLE   - Caso o identificador dito como variavel esteja sendo usado como funcao.
ERR_UNDECLARED - Caso o identificador não tenha sido declarado no seu uso; */
void verificaERR_VARIABLE_UNDECLARED_chamadafuncao(Pilha_tabelas *pilha, char *valor, int num_linha)
{
    NodoPilha* lista_atual = pilha->topo;

    while (lista_atual != NULL) {
        Tabela* tabela_atual = lista_atual->tabela;
        NodoTabela* nodo_tabela_atual = tabela_atual->primeiro;

        while (nodo_tabela_atual != NULL) {
            if (strcmp(valor, nodo_tabela_atual->info->valor) == 0) {
                if (nodo_tabela_atual->info->natureza != FUNCTION) {
                    printf("ERRO DE SEMANTICA - LINHA %d - VARIAVEL '%s' SENDO USADA COMO FUNCAO\n", num_linha, valor);
                    exit(ERR_VARIABLE);
                }  
            }
            nodo_tabela_atual = nodo_tabela_atual->proximo;
        }
        lista_atual = lista_atual->proximo;
    }

    printf("ERRO DE SEMANTICA - LINHA %d - IDENTIFICADOR '%s' NAO DECLARADO\n", num_linha, valor);
    exit(ERR_UNDECLARED); 
}

/* Verifica o seguinte erro de semantica:
ERR_DECLARED - Nos casos em que um identificador ja declarado esteja sendo redeclarado. */
void verificaERR_DECLARED(Pilha_tabelas *pilha, VALOR_LEXICO* identificador)
{
    NodoPilha* lista_atual = pilha->topo;

    if (identificador->natureza != FUNCTION) {
        while (lista_atual != NULL) {
            Tabela* tabela_atual = lista_atual->tabela;
            NodoTabela* nodo_tabela_atual = tabela_atual->primeiro;

            while (nodo_tabela_atual != NULL) {
                if (strcmp(identificador->valor, nodo_tabela_atual->info->valor) == 0) {
                    printf("ERRO DE SEMANTICA - LINHA %d - REDECLARACAO DO IDENTIFICADOR '%s'\n", identificador->num_linha, identificador->valor);
                    exit(ERR_DECLARED);
                }
                nodo_tabela_atual = nodo_tabela_atual->proximo;
            }
            lista_atual = lista_atual->proximo;
        }
    }
}

// Imprime a última tabela da pilha
void imprimeUltimaTabelaDaPilha(Pilha_tabelas* pilha) {
    NodoPilha* atual = pilha->topo;
    if (atual == NULL) {
        printf("Pilha está vazia\n");
        return;
    }

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    printf("TABELA LOCAL:\n\n");
    imprimeTabela(atual->tabela);
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

// Obtém o tipo de um identificador
int obtemTipo(Pilha_tabelas* pilha, VALOR_LEXICO* identificador) {
    NodoPilha* lista_atual = pilha->topo;
    int tipo_atual = -1;

    while (lista_atual != NULL) {
        Tabela* tabela_atual = lista_atual->tabela;
        NodoTabela* nodo_tabela_atual = tabela_atual->primeiro;

        while (nodo_tabela_atual != NULL) {
            if (strcmp(identificador->valor, nodo_tabela_atual->info->valor) == 0) {
                tipo_atual = nodo_tabela_atual->info->tipo; 
            }
            nodo_tabela_atual = nodo_tabela_atual->proximo;
        }
        lista_atual = lista_atual->proximo;
    }
    
    return tipo_atual;  
}

/*//Recebe duas listas de nos da AST, e concatena as duas. 
void concatenate_list(NODO* list1, NODO* list2) {
    NODO* last_node_from_list = get_last_valid_node_from_list(list1);
    adicionaNODO(last_node_from_list, list2);
}*/