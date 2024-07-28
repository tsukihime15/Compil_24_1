#ifndef VALOR_LEXICO_H
#define VALOR_LEXICO_H

#include <string.h>
#include <stdlib.h>

typedef enum TIPO_TOKEN
{
    FLOAT,
    INTEIRO,
    BOOLEANO,
    SEM_TIPO
} TIPO_TOKEN;

typedef enum NATUREZA
{
    ID,
    FUNC,
    SEM_NATUREZA
} NATUREZA;

typedef struct VALOR_LEXICO
{
    int num_linha;
    NATUREZA natu;
    TIPO_TOKEN tipo;
    char* valor;
} VALOR_LEXICO;

VALOR_LEXICO createValorLexico(char* valor, NATUREZA natu, TIPO_TOKEN tipo, int num_linha);
void freeValorLexico(VALOR_LEXICO valor_lexico);

#endif
