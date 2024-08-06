#include "valor_lexico.h"

VALOR_LEXICO createValorLexico(char* valor, int natureza, int tipo, int num_linha)
{
    VALOR_LEXICO valor_lexico;
    valor_lexico.num_linha = num_linha;
    valor_lexico.natureza = natureza;
    valor_lexico.tipo = tipo;
    valor_lexico.valor = strdup(valor);

    return valor_lexico;
}

void freeValorLexico(VALOR_LEXICO valor_lexico)
{
    if (!valor_lexico.valor) 
        return;

    free(valor_lexico.valor);
}