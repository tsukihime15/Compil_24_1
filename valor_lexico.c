#include "valor_lexico.h"

VALOR_LEXICO createValorLexico(char* valor, NATUREZA natu, TIPO_TOKEN tipo, int num_linha)
{
    VALOR_LEXICO valor_lexico;
    valor_lexico.num_linha = num_linha;
    valor_lexico.natu = natu;
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