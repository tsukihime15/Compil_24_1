#include <stdio.h>
//#include "pilha_tabelas.h"
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
void *pilha_de_tabelas = NULL;
void *tabela_global = NULL;
void *tabela_escopo = NULL;
void criaTabelaGlobal(void* pilha_de_tabelas);
void criaTabelaMain(void* entrada);
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  //exporta (arvore);
  criaTabelaGlobal(pilha_de_tabelas);
  criaTabelaMain(tabela_global);
  criaTabelaMain(tabela_escopo);
  yylex_destroy();
  return ret;
}