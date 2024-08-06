#ifndef VALOR_LEXICO_H
#define VALOR_LEXICO_H

#include <string.h>
#include <stdlib.h>

/*Constante para definir o tipo de um token*/
#define INT 0
#define FLOAT 1
#define BOOL 2
#define SEM_TIPO 3

/* Constantes para definir a natureza de um token */
#define LITERAL 0
#define VARIABLE 1
#define EXPRESSION_OPERATOR 2
#define LANGUAGE_OPERATOR 3
#define CONTROL 4
#define TYPE 5
#define SYNTAX_TOKEN 6
#define FUNCTION_CALL 7
#define FUNCTION 8
#define SEM_NATUREZA 9

typedef struct VALOR_LEXICO
{
    int num_linha;
    int tipo;    
    int natureza;

    char* valor;
} VALOR_LEXICO;

VALOR_LEXICO createValorLexico(char* valor, int natu, int tipo, int num_linha);
void freeValorLexico(VALOR_LEXICO valor_lexico);

#endif
