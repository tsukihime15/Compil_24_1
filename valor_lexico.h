#ifndef VALOR_LEXICO_H
#define VALOR_LEXICO_H

#include <string.h>
#include <stdlib.h>

typedef enum TIPO_TOKEN
{
    IDENTIFICADOR,
    LITERAL,
    OUTRO
} TIPO_TOKEN;

typedef struct VALOR_LEXICO
{
    int num_linha;
    TIPO_TOKEN tipo;
    char* valor;
} VALOR_LEXICO;

VALOR_LEXICO createValorLexico(char* valor, TIPO_TOKEN tipo, int num_linha);
void freeValorLexico(VALOR_LEXICO valor_lexico);

#endif