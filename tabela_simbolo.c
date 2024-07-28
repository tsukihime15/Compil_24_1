#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_simbolo.h"
#include "valor_lexico.h"

// Função para criar uma nova tabela de símbolos
TabelaSimbolos* criarTabelaSimbolos() {
    TabelaSimbolos* tabela = (TabelaSimbolos*)malloc(sizeof(TabelaSimbolos));
    tabela->primeiro = NULL;
    return tabela;
}

// Função para criar uma nova entrada na tabela de símbolos
Simbolo* criarSimbolo(char* lexema, EntradaTabelaSimbolos entrada) {
    Simbolo* simbolo = (Simbolo*)malloc(sizeof(Simbolo));
    simbolo->lexema = strdup(lexema);
    simbolo->entrada = entrada;
    return simbolo;
}

EntradaTabelaSimbolos* criaEntradaTabelaSimbolos(VALOR_LEXICO valor_lexico){
    /*if(valor_lexico == NULL){
        printf("valor_lexico vazio");
        exit(1);
    }*/  
    EntradaTabelaSimbolos* entrada = (EntradaTabelaSimbolos*)malloc(sizeof(EntradaTabelaSimbolos));
    entrada->linha = valor_lexico.num_linha;
    
    if (valor_lexico.natu == ID){
        entrada->natureza = IDENTIFICADOR;
    }
    else if (valor_lexico.natu == FUNC){
        entrada->natureza = FUNCAO;
    }
    //entrada->tipo = valor_lexico.tipo;      
    if (valor_lexico.tipo == INTEIRO){   
        strcpy(entrada->tipo, "int" );
        entrada->valor.int_val = atoi(valor_lexico.valor);
    }
    else if (valor_lexico.tipo == BOOLEANO){   
        strcpy(entrada->tipo, "bool" );
        strcpy(entrada->valor.string_val, valor_lexico.valor);
    }
    else if (valor_lexico.tipo == FLOAT){   
        strcpy(entrada->tipo, "float" );
        entrada->valor.float_val = atof(valor_lexico.valor);
    }

    return entrada;
}

// Função para inserir uma nova entrada na tabela de símbolos
void inserirSimbolo(TabelaSimbolos* tabela,char* lexema, EntradaTabelaSimbolos entrada) {
    Simbolo* simbolo = criarSimbolo(lexema, entrada);
    simbolo->proximo = tabela->primeiro;
    tabela->primeiro = simbolo;
}

// Função para buscar um símbolo na tabela de símbolos
Simbolo* buscarSimbolo(TabelaSimbolos* tabela,char* lexema) {
    Simbolo* atual = tabela->primeiro;
    while (atual != NULL) {
        if (strcmp(atual->lexema, lexema) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Função para liberar a memória da tabela de símbolos
void liberarTabelaSimbolos(TabelaSimbolos* tabela) {
    Simbolo* atual = tabela->primeiro;
    while (atual != NULL) {
        Simbolo* proximo = atual->proximo;
        free(atual->lexema);
        free(atual);
        atual = proximo;
    }
    free(tabela);
}

