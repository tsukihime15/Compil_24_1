#include <stdio.h>
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);
PilhaTabelaSimbolos *pilha_de_tabelas = NULL;
TabelaSimbolos *tabela_global = NULL;
TabelaSimbolos *tabela_escopo = NULL;
int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  yylex_destroy();
  return ret;
}