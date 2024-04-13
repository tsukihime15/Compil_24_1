%{
int yylex(void);
void yyerror (char const *mensagem);
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
programa: program_list | ;
program_list: program_list decl | program_list func | ;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis
decl: id_list ',';
// Lista de identificadores
id_list: id_list type TK_IDENTIFICADOR ';' | ;
// Tipos
type: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;
// Função => cabeçalho e corpo
func: header '{' body '}';
// Cabeçalho => Parâmetros OR Tipo \ Identificador
header: '(' params_list ')' TK_OC_OR type '\\' TK_IDENTIFICADOR;
// Params: Tipo e lista de parâmetros
params_list: params_list ';' param | param;
param: type TK_IDENTIFICADOR | ;
// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block;
command_block: '[' command_list ']';
command_list: command_list simple_command ',' | ;
simple_command: command_block | decl | atr | fcall | return | cflow;
else_command: TK_PR_ELSE command_block | ;
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' '(' expr ')' ',';
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')' ',';
args_list: args_list ',' expr | expr;
expr: operand operator7 | operator1;
// Retorno
return: TK_PR_RETURN expr ',';
// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' command_block else_command | TK_PR_WHILE '(' expr ')' command_block;
operand: TK_IDENTIFICADOR | literal | fcall;
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE;
operator7: | TK_OC_OR expr | operator6;
operator6: TK_OC_AND expr | operator5;
operator5: TK_OC_EQ expr | TK_OC_NE expr | operator4;
operator4: '<' expr | '>' expr | TK_OC_LE expr | TK_OC_GE expr | operator3;
operator3: '+' expr | '-' expr | operator2;
operator2: '*' expr | '/' expr | '%' expr | operator1;
operator1: '-' expr | '!' expr | operator0;
operator0: '(' expr ')';


