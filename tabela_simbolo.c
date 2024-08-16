#include "tabela_simbolo.h"

/*Cria um Tabela*/
void inicializaTabela(Tabela* tabela)
{
    tabela->primeiro = NULL;
}

// Insere valor léxico na tabela
void insereValorLexicoNaTabela(Tabela* tabela, VALOR_LEXICO* valor_lexico) {
    NodoTabela* nodo_tabela = criarNodoTabela(valor_lexico);
    nodo_tabela->proximo = tabela->primeiro;
    tabela->primeiro = nodo_tabela;
}

// Destroi a tabela
void destroiTabela(Tabela* tabela) {
    NodoTabela* atual = tabela->primeiro;
    NodoTabela* proximoNodo;
    while (atual != NULL) {
        proximoNodo = atual->proximo;
        free(atual->info); // Liberar memória do VALOR_LEXICO
        free(atual);
        atual = proximoNodo;
    }
}

NodoTabela* criarNodoTabela(VALOR_LEXICO* valor_lexico) {
    NodoTabela* novo = (NodoTabela*)malloc(sizeof(NodoTabela));
    if (novo == NULL) {
        printf("Falha ao alocar memória\n");
    }
    novo->info = valor_lexico;
    novo->proximo = NULL;
    return novo;
}

// Imprime a tabela
void imprimeTabela(Tabela *tabela)
{
    NodoTabela* atual = tabela->primeiro;

    while (atual != NULL) {
        printf("VALOR: %s\n", atual->info->valor);
        printf("TIPO: %d\n", atual->info->tipo);
        printf("NATUREZA: %d\n", atual->info->natureza);
        printf("LINHA: %d\n", atual->info->num_linha);
        atual = atual->proximo;
    }
}

