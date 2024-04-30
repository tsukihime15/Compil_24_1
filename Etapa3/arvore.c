#include "arvore.h"

NODO* createNodo(VALOR_LEXICO valor_lexico)
{
    NODO* nodo = malloc(sizeof(NODO));

    nodo->valor_lexico = valor_lexico;
    nodo->pai = NULL;
    nodo->irmao = NULL;
    nodo->filho = NULL;

    return nodo;
}

NODO* createNodoToFunctionCall(VALOR_LEXICO valor_lexico)
{
    NODO* nodo = createNodo(valor_lexico);

    char* start = "call ";
    char* novo_valor = malloc(strlen(start) + strlen(nodo->valor_lexico.valor) + 1);

    strcpy(novo_valor, start);
    strcat(novo_valor, nodo->valor_lexico.valor);

    free(nodo->valor_lexico.valor);
    nodo->valor_lexico.valor = novo_valor;

    return nodo;
}

void addFilho(NODO* pai, NODO* filho)
{
    if (!filho) return;

    if (!pai)
    {
        removeNodo(pai);
        return;
    }

    NODO* ultimo_filho = getUltimoFilho(pai);
    if (ultimo_filho)
    {
        ultimo_filho->irmao = filho;
    }
    else
    {
        pai->filho = filho;
    }
    filho->pai = pai;
}

NODO* getUltimoFilho(NODO* pai)
{
    NODO* esse_filho = NULL;
    NODO* ultimo_filho = pai->filho;
    while (ultimo_filho)
    {
        esse_filho = ultimo_filho;
        ultimo_filho = ultimo_filho->irmao;
    }
    return esse_filho;
}

void removeNodo(NODO* nodo)
{
    if (!nodo) return;

    freeValorLexico(nodo->valor_lexico);

    removeNodo(nodo->filho);
    removeNodo(nodo->irmao);

    free(nodo);
}

void exporta(NODO* nodo)
{
    if (!nodo) return;

    printHeader(nodo);
    printArvore(nodo);
}

void printHeader(NODO* nodo)
{
    printf("%p [valor=\"%s\"];\n", nodo, nodo->valor_lexico.valor);
    if (nodo->filho)
    {
        printHeader(nodo->filho);
    }
    if (nodo->irmao)
    {
        printHeader(nodo->irmao);
    }
}

void printArvore(NODO* nodo)
{
    if (nodo->pai)
    {
        printf("%p, %p\n", nodo->pai, nodo);
    }
    if (nodo->filho)
    {
        printArvore(nodo->filho);
    }
    if (nodo->irmao)
    {
        printArvore(nodo->irmao);
    }
}