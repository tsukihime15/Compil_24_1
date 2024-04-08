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
programa: decl | func | ;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis
decl: id_list ',';
// Lista de identificadores
id_list: type TK_IDENTIFICADOR ';' id_list;
id_list: type TK_IDENTIFICADOR;
// Tipos
type: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;
// Função => cabeçalho e corpo
func: header '{' body '}';
// Cabeçalho => Parâmetros OR Tipo \ Identificador
header: '(' params ')' TK_OC_OR type '\\' TK_IDENTIFICADOR;
// Params: Tipo e lista de parâmetros
params: type TK_IDENTIFICADOR ';' params;
params: type TK_IDENTIFICADOR | ;
// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: decl | atr | fcall | return | cflow | body | ;
expr: operand (operator | )',';
// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' '(' expr ')' ',';
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' expr ')' ',';
// Retorno
return: 'return' expr ',';
// Controle de Fluxo
cflow: TK_PR_IF '(' expr ')' body ((TK_PR_ELSE body) | ) | TK_PR_WHILE '(' expr ')' body ',';
operand: (TK_IDENTIFICADOR | literal | fcall) ',';
operator: ',';
literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE;
%%
