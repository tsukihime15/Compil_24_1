#include "pilha_tabelas.h"
#include "tabela_simbolo.h"
// Funções para manipular a pilha de tabelas de símbolos
PilhaTabelaSimbolos* criarPilha() {
    PilhaTabelaSimbolos* pilha = (PilhaTabelaSimbolos*)malloc(sizeof(PilhaTabelaSimbolos));
    pilha->tabela = criarTabelaSimbolos();  // Tabela global
    pilha->proximo = NULL;
    return pilha;
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

void verificarDeclaracao(PilhaTabelaSimbolos* pilha, char* lexema) {
    int linha = 0;
printf("0");
    PilhaTabelaSimbolos* atual = pilha;
    printf("1");
    while (atual != NULL) {
printf("2");
        Simbolo* simbolo = buscarSimbolo(atual->tabela, lexema);
printf("3");
        linha = simbolo->entrada.linha;
printf("4");
        if (simbolo != NULL) {
            return;
        }
        atual = atual->proximo;
    } 
    printf("Erro semântico na linha %d: Identificador '%s' não declarado (ERR_UNDECLARED).\n", linha, lexema);
    exit(ERR_UNDECLARED);
}

void declararIdentificador(PilhaTabelaSimbolos* pilha, char* lexema, EntradaTabelaSimbolos entrada, int linha) {
    TabelaSimbolos* tabelaAtual = obterTabelaAtual(pilha);
    if (buscarSimbolo(tabelaAtual, lexema) != NULL) {
        printf("Erro semântico na linha %d: Identificador '%s' já declarado (ERR_DECLARED).\n", linha, lexema);
        exit(ERR_DECLARED);
    }
    inserirSimbolo(tabelaAtual, lexema, entrada);
}

void verificarUsoIdentificador(PilhaTabelaSimbolos* pilha, char* lexema, int linha, int naturezaEsperada) {
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

void limparPilha(PilhaTabelaSimbolos* pilha) {
    while (pilha != NULL) {
        desempilhar(&pilha);
    }
}

