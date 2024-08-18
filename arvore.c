#include "arvore.h"

NODO* createNodo(VALOR_LEXICO* valor_lexico)
{
    NODO* nodo = malloc(sizeof(NODO));
    if (!nodo) return NULL;

    nodo->valor_lexico = valor_lexico;
    nodo->pai = NULL;
    nodo->irmao = NULL;
    nodo->filho = NULL;

    return nodo;
}

NODO* createFcallNodo(VALOR_LEXICO* valor_lexico)
{
 
    NODO* nodo = createNodo(createValorLexico(valor_lexico->valor, valor_lexico->natureza, valor_lexico->tipo, valor_lexico->num_linha));
    if (!nodo) return NULL;

    char* novo_valor = malloc(strlen("call ") + strlen(nodo->valor_lexico->valor) + 1);
    if (!novo_valor) return NULL;

    char* call_string = "call ";
    strcpy(novo_valor, call_string);
    strcat(novo_valor, nodo->valor_lexico->valor);

    free(nodo->valor_lexico->valor);
    nodo->valor_lexico->valor = novo_valor;
    
    return nodo;
}

void addFilho(NODO* pai, NODO* filho)
{
    if (!filho) return;

    if (!pai)
    {
        removeNodo(filho);
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

    removeNodo(nodo->filho);
    removeNodo(nodo->irmao);

    freeValorLexico(nodo->valor_lexico);
    
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
    printf("%p [label=\"%s\"];\n", nodo, nodo->valor_lexico->valor);
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
    if (!nodo) return;

    // DEBUG de LOOP: Verifique se já foi impresso antes
    static void* visited[1000]; 
    static int visited_count = 0;

    for (int i = 0; i < visited_count; i++) {
        if (visited[i] == nodo) {
            return; // Já visitado
        }
    }
    visited[visited_count++] = nodo;

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
