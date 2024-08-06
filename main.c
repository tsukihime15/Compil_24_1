#include <stdio.h>
#include "arvore.h"
#include "tabela_simbolo.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
Lista_tabelas *lista_tabelas = NULL;
Tabela *tabela_global = NULL;
Tabela *tabela_escopo = NULL;
//void exporta (void *arvore);

int main (int argc, char **argv)
{ 

  int ret = yyparse(); 
  //exporta (arvore);
  yylex_destroy();
  return ret;
}
