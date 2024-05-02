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

NODO* createFcallNodo(VALOR_LEXICO valor_lexico)
{
 
    char* novo_valor = strcat("call ", valor_lexico.valor);
    VALOR_LEXICO novo_valor_lexico = createValorLexico(novo_valor, valor_lexico.tipo, valor_lexico.num_linha);
 
    NODO* nodo = createNodo(novo_valor_lexico);
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

    printValorLexico(nodo);
    printArvore(nodo);
}

void printValorLexico(NODO* nodo)
{
    printf("%p [label=\"%s\"];\n", nodo, nodo->valor_lexico.valor);
    if (nodo->filho)
    {
        printValorLexico(nodo->filho);
    }
    if (nodo->irmao)
    {
        printValorLexico(nodo->irmao);
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
