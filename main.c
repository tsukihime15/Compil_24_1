#include <stdio.h>
#include "pilha_tabelas.h"
#include "tabela_simbolo.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
//void exporta (void *arvore);

int main (int argc, char **argv)
{ 

  int ret = yyparse(); 
  //exporta (arvore);
  yylex_destroy();
  return ret;
}
