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

%type<nodo> programa
%type<nodo> program_list
%type<nodo> decl

%type<nodo> id_list
%type<nodo> type

%%
// Símbolo inicial
programa: program_list                       {$$ = $1; arvore = $$;}
     ;                      
program_list: program_list decl ','          {$$ = $2;}
     | program_list func                     //{$$ = $2;}
     |                                       {$$ = NULL;}
     ;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis
decl: type id_list TK_IDENTIFICADOR          {$$ = createNodo($3);}
     ;
// Lista de identificadores
id_list: id_list TK_IDENTIFICADOR ';'        {$$ = createNodo($2);}
     |                                       {$$ = NULL;}
     ;
// Tipos
type: TK_PR_INT          {$$ = createNodo($1);}
     | TK_PR_FLOAT       {$$ = createNodo($1);}
     | TK_PR_BOOL        {$$ = createNodo($1);}
     ;
// Função => cabeçalho e corpo
func: header body
     ;
// Cabeçalho => Parâmetros OR Tipo / Identificador
header: '(' params_list_void ')' TK_OC_OR type '/' TK_IDENTIFICADOR
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
body: command_block
     ;
command_block: '{' '}'
     ;
command_block: '{' command_list '}'
     ;
command_list: command_list simple_command ',' 
     | simple_command ','
     ;
simple_command: command_block 
     | decl 
     | atr 
     |fcall 
     | return 
     | cflow
     ;
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr 
     ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')'
     ;
// NAO ACEITA argumentos vazio()
args_list: args_list ';' expr 
     | expr
     ;
// Retorno
return: TK_PR_RETURN expr
     ;
// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' command_block else_command
     | TK_PR_WHILE '(' expr ')' command_block
     ;
else_command: TK_PR_ELSE command_block 
     | 
     ;

//Expressao
expr: expr8 
     | 
     ;
expr8: expr8 TK_OC_OR expr7 
     | expr7
     ;
expr7: expr7 TK_OC_AND expr6 
     | expr6
     ;
expr6: expr6 TK_OC_EQ expr5 
     | expr6 TK_OC_NE expr5 
     | expr5
     ;
expr5: expr5 '<' expr4 
     | expr5 '>' expr4 
     | expr5 TK_OC_LE expr4 
     | expr5 TK_OC_GE expr4 
     | expr4
     ;
expr4: expr4 '+' expr3 
     | expr4 '-' expr3 
     | expr3
     ;
expr3: expr3 '*' expr2 
     | expr3 '/' expr2 
     | expr3 '%' expr2 
     | expr2
     ;
expr2: '-' expr2 
     | '!' expr2 
     | expr1
     ;
expr1: '(' expr ')'
     | expr0
     ;
expr0: operand
     ;

operand: TK_IDENTIFICADOR 
     | literal 
     | fcall
     ;
literal: TK_LIT_INT 
     | TK_LIT_FLOAT 
     | TK_LIT_FALSE 
     | TK_LIT_TRUE
     ;
%%
