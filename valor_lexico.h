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
#define GLOBAL_DECL 1
#define VARIABLE 2
#define ATRIBUITION 3
#define OPERATOR 4
#define CONTROL 5
#define TYPE 6
#define RETURN 7
#define FUNCTION_CALL 8
#define FUNCTION 9
#define SEM_NATUREZA 99

typedef struct VALOR_LEXICO
{
    int num_linha;
    int tipo;    
    int natureza;

    int deslocamento;

    char* valor;
} VALOR_LEXICO;

VALOR_LEXICO* createValorLexico(char* valor, int natu, int tipo, int num_linha);
void freeValorLexico(VALOR_LEXICO* valor_lexico);

#endif
