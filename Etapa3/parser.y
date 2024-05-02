%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342  */
#include <stdio.h>
#include "arvore.h"
#include "valor_lexico.h"

int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);

extern void* arvore;
%}

// %code requires
// {
//     #include "arvore.h"
//      #include "valor_lexico.h"
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
%type<nodo> program_list
%type<nodo> func
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
%type<nodo> cflow
%type<nodo> else_command


%%
// Símbolo inicial
programa: program_list                       {$$ = $1; arvore = $$;}
     ;                      
program_list: program_list decl ','          {$$ = $1;} /* nao fazer p/ decl */
     | program_list func                     {if($1 != NULL){
                                                  addFilho($1,$2);
                                                  $$ = $1;}
                                              else
                                                  $$ = $2;
                                             }
     |                                       {$$ = NULL;}
     ;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis
decl: type id_list TK_IDENTIFICADOR          /* nao fazer p/ decl */
     ;
// Lista de identificadores
id_list: id_list TK_IDENTIFICADOR ';'        /* nao fazer p/ decl */
     |                                       
     ;
// Tipos
type: TK_PR_INT          
     | TK_PR_FLOAT       
     | TK_PR_BOOL        
     ;
// Função => cabeçalho e corpo
func: header body                            {addFilho($1,$2);
                                              $$ = $1;}
     ;
// Cabeçalho => Parâmetros OR Tipo / Identificador
header: '(' params_list_void ')' TK_OC_OR type '/' TK_IDENTIFICADOR   {$$ = createNodo($7);}
     ;
// Params: Tipo e lista de parâmetros
params_list_void: params_list 
     | 
     ;
params_list: params_list ';' param 
     | param
     ;
param: type TK_IDENTIFICADOR
     ;
// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block                               {$$ = $1;}
     ;
// Aceita bloco com comando vazio 
command_block: '{' '}'                            {$$ = NULL;}
     ;
command_block: '{' command_list '}'               {$$ = $2;}
     ;
command_list: command_list simple_command ','     {addFilho($1,$2);
                                                   $$ = $1;
                                                  }
     | simple_command ','                         {$$ = $1;}
     ;
simple_command: command_block      {$$ = $1;}
     | decl                        {$$ = NULL;}
     | atr                         {$$ = $1;}
     | fcall                       {$$ = $1;}
     | return                      {$$ = NULL;}
     | cflow                       {$$ = $1;}
     ;
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr     {$$ = createNodo($2);
                                    addFilho($$, createNodo($1));
                                    addFilho($$, $3);
                                   }
     ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')'    {$$ = createFcallNodo($1);
                                              addFilho($$,$3);
          // ESSE eh o dificil, preciso usar createValorLexico onde o valor eh "call "+TK_IDENTIFIER
          //mas o TK_IDENTIFIER jah eh um VALOR_LEXICO, entao tenho q acessar o .valor e o .num_linha dele
          // tentei com $1.valor mas deu seg. fault 
                                             }
     ;
// agora aceita argumentos vazio()
args_list: args_list ';' expr                {$$ = $3;}
     | expr                                  {$$ = $1;}
     ;
// Retorno
return: TK_PR_RETURN expr       {$$ = createNodo($1);
                                 addFilho($$,$2);
                                }              
     ;
//nao entendi o q eh pra por, na E3 diz "usar o lexema correspondente como label"
// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' command_block else_command     {$$ = createNodo($1);
                                                             addFilho($$,$3);
                                                             addFilho($$,$5);
                                                             addFilho($$,$6);
                                                            }
     | TK_PR_WHILE '(' expr ')' command_block               {$$ = createNodo($1);
                                                             addFilho($$,$3);
                                                             addFilho($$,$5);
                                                            }
     ;
else_command: TK_PR_ELSE command_block                      {$$ = $2;}
     |                                                      {$$ = NULL;}
     ;

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
expr1: '(' expr ')'           {$$ = createNodo($1);
                               addFilho($$, $2);
                              }
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
