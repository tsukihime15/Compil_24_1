%{
#include <stdio.h>
int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);
%}
%define parse.error verbose
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO
%%
// Símbolo inicial
programa: program_list;
program_list: program_list decl ','| program_list func | ;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis
decl: type id_list TK_IDENTIFICADOR;
// Lista de identificadores
id_list: id_list TK_IDENTIFICADOR ';' | ;
// Tipos
type: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;
// Função => cabeçalho e corpo
func: header body;
// Cabeçalho => Parâmetros OR Tipo / Identificador
header: '(' params_list_void ')' TK_OC_OR type '/' TK_IDENTIFICADOR;
// Params: Tipo e lista de parâmetros
params_list_void: params_list | ;
params_list: params_list ';' param | param;
param: type TK_IDENTIFICADOR;
// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block;
command_block: '{' command_list '}';
command_list: command_list simple_command ',' | simple_command ',' | ',';
simple_command: command_block | decl | atr |fcall | return | cflow;
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')';
// NAO ACEITA argumentos vazio()
args_list: args_list ';' expr | expr;
// Retorno
return: TK_PR_RETURN expr;
// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' command_block else_command
     | TK_PR_WHILE '(' expr ')' command_block;
else_command: TK_PR_ELSE command_block | ;

//Expressao
expr: expr8 ;
expr8: expr8 TK_OC_OR expr7 | expr7;
expr7: expr7 TK_OC_AND expr6 | expr6;
expr6: expr6 TK_OC_EQ expr5 | expr6 TK_OC_NE expr5 | expr5;
expr5: expr5 '<' expr4 | expr5 '>' expr4 | expr5 TK_OC_LE expr4 
     | expr5 TK_OC_GE expr4 | expr4;
expr4: expr4 '+' expr3 | expr4 '-' expr3 | expr3;
expr3: expr3 '*' expr2 | expr3 '/' expr2 | expr3 '%' expr2 | expr2;
expr2: '-' expr1 | '!' expr1 | expr1;
expr1: '(' expr0 ')'| expr0;
expr0: operand;

operand: TK_IDENTIFICADOR | literal | fcall;
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE;
%%


