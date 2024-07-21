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

// Funções para manipular a pilha de tabelas de símbolos
PilhaTabelaSimbolos* criarPilha() {
    PilhaTabelaSimbolos* pilha = (PilhaTabelaSimbolos*)malloc(sizeof(PilhaTabelaSimbolos));
    pilha->tabela = criarTabelaSimbolos();  // Tabela global
    pilha->proximo = NULL;
    return pilha;
}

EntradaTabelaSimbolos criaEntradaTabelaSimbolos(VALOR_LEXICO valor_lexico){  
    EntradaTabelaSimbolos* entrada = (EntradaTabelaSimbolos*)malloc(sizeof(EntradaTabelaSimbolos));
    entrada->linha = valor_lexico.num_linha;
    entrada->natureza = valor_lexico.natu;  // IDENTIFICADOR == ID/ FUNCAO == FUNC
    //entrada->tipo = valor_lexico.tipo;      // if (valor.lexico.tipo == INTEIRO) strccpy(entrada->tipo, "int" ); 
    //strcpy(entrada->valor, valor_lexico.valor);

    return *entrada;
}

void empilhar(PilhaTabelaSimbolos** pilha, TabelaSimbolos* tabela) {
    PilhaTabelaSimbolos* novaPilha = (PilhaTabelaSimbolos*)malloc(sizeof(PilhaTabelaSimbolos));
    novaPilha->tabela = tabela;
    novaPilha->proximo = *pilha;
    *pilha = novaPilha;
}

void desempilhar(PilhaTabelaSimbolos** pilha) {
    if (*pilha == NULL) return;

    PilhaTabelaSimbolos* temp = *pilha;
    *pilha = (*pilha)->proximo;
    liberarTabelaSimbolos(temp->tabela);
    free(temp);
}

TabelaSimbolos* obterTabelaAtual(PilhaTabelaSimbolos* pilha) {
    if (pilha == NULL) return NULL;
    return pilha->tabela;
}

void verificarDeclaracao(PilhaTabelaSimbolos* pilha, const char* lexema, int linha) {
    PilhaTabelaSimbolos* atual = pilha;
    while (atual != NULL) {
        Simbolo* simbolo = buscarSimbolo(atual->tabela, lexema);
        if (simbolo != NULL) {
            return;
        }
        atual = atual->proximo;
    }
    printf("Erro semântico na linha %d: Identificador '%s' não declarado (ERR_UNDECLARED).\n", linha, lexema);
    exit(ERR_UNDECLARED);
}

void declararIdentificador(PilhaTabelaSimbolos* pilha, const char* lexema, EntradaTabelaSimbolos entrada, int linha) {
    TabelaSimbolos* tabelaAtual = obterTabelaAtual(pilha);
    if (buscarSimbolo(tabelaAtual, lexema) != NULL) {
        printf("Erro semântico na linha %d: Identificador '%s' já declarado (ERR_DECLARED).\n", linha, lexema);
        exit(ERR_DECLARED);
    }
    inserirSimbolo(tabelaAtual, lexema, entrada);
}

void verificarUsoIdentificador(PilhaTabelaSimbolos* pilha, const char* lexema, int linha, Natureza naturezaEsperada) {
    PilhaTabelaSimbolos* atual = pilha;
    while (atual != NULL) {
        Simbolo* simbolo = buscarSimbolo(atual->tabela, lexema);
        if (simbolo != NULL) {
            if (simbolo->entrada.natureza != naturezaEsperada) {
                if (naturezaEsperada == IDENTIFICADOR) {
                    printf("Erro semântico na linha %d: Identificador '%s' usado como variável (ERR_VARIABLE).\n", linha, lexema);
                    exit(ERR_VARIABLE);
                } else if (naturezaEsperada == FUNCAO) {
                    printf("Erro semântico na linha %d: Identificador '%s' usado como função (ERR_FUNCTION).\n", linha, lexema);
                    exit(ERR_FUNCTION);
                }
            }
            return;
        }
        atual = atual->proximo;
    }
    printf("Erro semântico na linha %d: Identificador '%s' não declarado (ERR_UNDECLARED).\n", linha, lexema);
    exit(ERR_UNDECLARED);
}

char* inferirTipo(AST* no, PilhaTabelaSimbolos* pilha) {
    if (no->filhoEsquerdo != NULL && no->filhoDireito != NULL) {
        char* tipoEsquerdo = inferirTipo(no->filhoEsquerdo, pilha);
        char* tipoDireito = inferirTipo(no->filhoDireito, pilha);
        
        if (strcmp(tipoEsquerdo, "int") == 0 && strcmp(tipoDireito, "int") == 0) {
            return "int";
        } else if (strcmp(tipoEsquerdo, "float") == 0 && strcmp(tipoDireito, "float") == 0) {
            return "float";
        } else if (strcmp(tipoEsquerdo, "bool") == 0 && strcmp(tipoDireito, "bool") == 0) {
            return "bool";
        } else if (strcmp(tipoEsquerdo, "float") == 0 || strcmp(tipoDireito, "float") == 0) {
            return "float";
        } else if (strcmp(tipoEsquerdo, "int") == 0 && strcmp(tipoDireito, "bool") == 0) {
            return "int";
        } else if (strcmp(tipoEsquerdo, "bool") == 0 && strcmp(tipoDireito, "int") == 0) {
            return "int";
        }
    } else if (no->filhoEsquerdo != NULL) {
        return inferirTipo(no->filhoEsquerdo, pilha);
    } else if (no->filhoDireito != NULL) {
        return inferirTipo(no->filhoDireito, pilha);
    }
    return no->tipo;  // Retorna o tipo se for um nó folha
}


