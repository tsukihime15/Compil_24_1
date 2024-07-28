%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342 | Mariana Koppe - 00219819 */
#include <stdio.h>
#include "arvore.h"
#include "pilha_tabelas.h"
#include "tabela_simbolo.h"

int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);

extern void* arvore;
void *pilha_de_tabelas;
void *tabela_global;
void *tabela_escopo;

%}

// %code requires
// {
//     #include "arvore.h"
//      #include "pilha_tabelas.h"
// }

%union
{
    VALOR_LEXICO valor_lexico;
    struct NODO* nodo;
}

%define parse.error verbose

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_ERRO

%token<valor_lexico> '-'
%token<valor_lexico> '+'
%token<valor_lexico> '*'
%token<valor_lexico> '/'
%token<valor_lexico> '%'
%token<valor_lexico> '<'
%token<valor_lexico> '>'
%token<valor_lexico> '|'
%token<valor_lexico> '~'
%token<valor_lexico> '='
%token<valor_lexico> '!'
%token<valor_lexico> '('

%type<nodo> programa
%type<nodo> raiz
%type<nodo> program_list
%type<nodo> element
%type<nodo> ident_func
%type<nodo> ident_decl
%type<nodo> ident_param
%type<nodo> func
%type<nodo> type
%type<nodo> decl_global
%type<nodo> decl_local
%type<nodo> id_list
%type<nodo> header
%type<nodo> body
%type<nodo> command_block
%type<nodo> command_list
%type<nodo> simple_command
%type<nodo> return
%type<nodo> atr
%type<nodo> expr
%type<nodo> expr8
%type<nodo> expr7
%type<nodo> expr6
%type<nodo> expr5
%type<nodo> expr4
%type<nodo> expr3
%type<nodo> expr2
%type<nodo> expr1
%type<nodo> expr0
%type<nodo> operand
%type<nodo> literal
%type<nodo> fcall
%type<nodo> args_list
%type<nodo> param
%type<nodo> params_list
%type<nodo> params_list_void
%type<nodo> cflow
%type<nodo> else_command


%%

// Símbolo inicial
raiz: cria_pilha
      empilha_tabela_escopo 
      programa
      desempilha_tabela_escopo 
      limpa_pilha                { $$ = $3; arvore = $$; tabela_global = tabela_escopo;}
;
programa: program_list               {$$ = $1; arvore = $$;}
;                      
programa:                            {$$ = NULL; arvore = NULL; }
;

program_list: element program_list { if($1 == NULL) 
                                    {$$ = $2;}
                                     else
                                        { 
                                        if($2 == NULL) {$$ = $1;}                   
                                            else { 
                                                {$$ = $1; addFilho($$,$2);}
                                                 }
                                        
                                        }
}
                | element {$$=$1;} 

;
element: decl_global  {$$ = NULL;} // Declaracoes nao sao usadas nessa etapa

        | func {$$ = $1;}
;
ident_decl: TK_IDENTIFICADOR {$$ = createNodo($1); verificarDeclaracao(pilha_de_tabelas,$1.valor);
EntradaTabelaSimbolos* entrada = criaEntradaTabelaSimbolos($1);
declararIdentificador(pilha_de_tabelas, $1.valor, *entrada, $1.num_linha);
};
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis globais
decl_global: type id_list ','             {$$ = NULL;}  // Declaracoes nao sao usadas nessa etapa
;
//Declaração de variáveis locais
decl_local: type id_list                 {$$ = NULL;} 
;
// Lista de identificadores
id_list: id_list ';' ident_decl    {$$ = $1;}// Declaracoes nao sao usadas nessa etapa
     | ident_decl                  {$$ = $1;}// Declaracoes nao sao usadas nessa etapa                 
     ;
// Tipos
type: TK_PR_INT    {$$ = NULL;} //tipos nao criam nodos nem sao filhos        
     | TK_PR_FLOAT {$$ = NULL;} //tipos nao criam nodos nem sao filhos         
     | TK_PR_BOOL  {$$ = NULL;} //tipos nao criam nodos nem sao filhos         
     ;
// Função => cabeçalho e corpo
// OBS: >>CABEÇALHOS<< FICAM NO ESCOPO GLOBAL
func: empilha_tabela_escopo header body desempilha_tabela_escopo {$$ = $2;
                                                                 addFilho($$,$3);}
     ;
// Cabeçalho => Parâmetros OR Tipo / Identificador
header: '(' params_list_void ')' TK_OC_OR type '/' ident_func   {$$ = $7;}
;
ident_func: TK_IDENTIFICADOR  {$$ = createNodo($1); verificarDeclaracao(pilha_de_tabelas,$1.valor); printf("Verificou declaracao\n");
EntradaTabelaSimbolos* entrada = criaEntradaTabelaSimbolos($1); printf("Criou entrada na tabela\n");
declararIdentificador(pilha_de_tabelas, $1.valor, *entrada, $1.num_linha); printf("Declarou identificador\n");
};
// Params: Tipo e lista de parâmetros
params_list_void: params_list {$$ = NULL;} //parametros nao criam nodos nem sao filhos
     | {$$=NULL;}                       
     ;
params_list: param ';' params_list {$$=NULL;}//parametros nao criam nodos nem sao filhos
    | param {$$=NULL;}
     ;
param: type ident_param {$$=NULL;}//parametros nao criam nodos nem sao filhos
     ;
ident_param: TK_IDENTIFICADOR {$$=NULL;}//parametros nao criam nodos nem sao filhos
;
// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block                               {$$ = $1;}
     ;
// Aceita bloco com comando vazio 
command_block: '{''}'                         {$$ = NULL;}
     ;
command_block: '{' command_list '}'           {$$ = $2;}
;
command_list: simple_command ',' command_list {if($1 == NULL) 
                                    {$$ = $3;}
                                     else
                                        { 
                                        if($3 == NULL) {$$ = $1;}                   
                                            else { 
                                                {$$ = $1; addFilho($$,$3);}
                                                 }
                                        
                                        }    }
     | simple_command ','                         {$$ = $1;}
     ;
simple_command: command_block      {$$ = $1;}
     | decl_local                  {$$ = $1;}
     | atr                         {$$ = $1;}
     | fcall                       {$$ = $1;}
     | return                      {$$ = $1;}
     | cflow                       {$$ = $1;}
     ;
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr     {$$ = createNodo($2);
                                    verificarUsoIdentificador(pilha_de_tabelas, $1.valor, $1.num_linha, IDENTIFICADOR);
                                    addFilho($$, createNodo($1));
                                    addFilho($$, $3);
                                   }
     ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')'   {$$ = createFcallNodo($1);
                                            verificarUsoIdentificador(pilha_de_tabelas, $1.valor, $1.num_linha, FUNCAO);
                                            addFilho($$,$3);
                                             }
     ;

args_list: expr  ';' args_list               {$$ = $1;
                                             addFilho($$, $3);}
     | expr                                  {$$ = $1;}
     ;
// Retorno
return: TK_PR_RETURN expr   {$$ = createNodo($1);
                                 addFilho($$,$2);
                                }              
     ;

// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' command_block else_command   {$$ = createNodo($1);
                                                             addFilho($$,$3);
                                                             addFilho($$,$5);
                                                             addFilho($$,$6);
                                                            }
     | TK_PR_WHILE '(' expr ')' command_block             {$$ = createNodo($1);
                                                             addFilho($$,$3);
                                                             addFilho($$,$5);
                                                            }
     ;
else_command: TK_PR_ELSE command_block                      {$$ = $2;}
     |                                                      {$$ = NULL;}
     ;

cria_pilha: { pilha_de_tabelas = criarPilha(); printf("Pilha criada\n"); };
empilha_tabela_escopo: /* Vazio */ { 
    tabela_escopo = criarTabelaSimbolos(); printf("Escopo criado\n");
    empilhar(pilha_de_tabelas, 
    tabela_escopo); printf("Tabela de escopo empilhada\n");
    }; 
desempilha_tabela_escopo: printf ("chama função desempilha!\n"); { desempilhar(pilha_de_tabelas); printf("Tabela de escopo desempilhada\n"); };
limpa_pilha: { limparPilha(pilha_de_tabelas); printf("Pilha limpa\n");};


//Expressao
expr: expr8                   {$$ = $1;}
     |                        {$$ = NULL;}
     ;
expr8: expr8 TK_OC_OR expr7   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr7                  {$$ = $1;}
     ;
expr7: expr7 TK_OC_AND expr6  {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr6                  {$$ = $1;}
     ;
expr6: expr6 TK_OC_EQ expr5   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr6 TK_OC_NE expr5   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5                  {$$ = $1;}
     ;
expr5: expr5 '<' expr4        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 '>' expr4        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 TK_OC_LE expr4   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 TK_OC_GE expr4   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr4                  {$$ = $1;}
     ;
expr4: expr4 '+' expr3        {$$ = createNodo($2);                           
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr4 '-' expr3        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr3                  {$$ = $1;}
     ;
expr3: expr3 '*' expr2        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);                            
                              }
     | expr3 '/' expr2        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr3 '%' expr2        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr2                  {$$ = $1;}
     ;
expr2: '-' expr2              {$$ = createNodo($1);
                               addFilho($$, $2);
                              }
     | '!' expr2              {$$ = createNodo($1);
                               addFilho($$, $2);
                              }
     | expr1                  {$$ = $1;}
     ;
expr1: '(' expr ')'           {$$ = $2;}
     | expr0                  {$$ = $1;}
     ;
expr0: operand                {$$ = $1;}
     ;

operand: TK_IDENTIFICADOR     {$$ = createNodo($1);}
     | literal                {$$ = $1;}
     | fcall                  {$$ = $1;}
     ;
literal: TK_LIT_INT           {$$ = createNodo($1);}
     | TK_LIT_FLOAT           {$$ = createNodo($1);}
     | TK_LIT_FALSE           {$$ = createNodo($1);}
     | TK_LIT_TRUE            {$$ = createNodo($1);}
     ;
%%
