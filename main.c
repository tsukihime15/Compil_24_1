#include <stdio.h>
#include "arvore.h"
#include "pilha_tabela.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (NODO* arvore);
void *pilha = NULL;
void *tabela = NULL;

int main (int argc, char **argv)
{ 

  int ret = yyparse(); 
  exporta (arvore);
  yylex_destroy();
  return ret;
}
