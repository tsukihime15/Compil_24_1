%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342 | Mariana Koppe - 00219819 */
#include <stdio.h>
#include "arvore.h"
#include "pilha_tabela.h"
#include "codigoAssembly.h"

int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);

extern void* arvore;

extern Pilha_tabelas* pilha;
extern Tabela* tabela;

%}

// %code requires
// {
//     #include "arvore.h"
//     #include "pilha_tabela.h"
// }

%union
{
    VALOR_LEXICO* valor_lexico;
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
%type<nodo> element
%type<nodo> ident_decl
%type<nodo> ident_func
%type<nodo> ident_param
%type<nodo> func
%type<nodo> type
%type<nodo> decl_global
%type<nodo> decl_local
%type<nodo> id_list_gl
%type<nodo> id_list_lc
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

%type<nodo> abrir_escopo_global
%type<nodo> fechar_escopo_global
%type<nodo> abrir_escopo_funcao
%type<nodo> fechar_escopo_funcao
%type<nodo> abrir_escopo_bloco
%type<nodo> fechar_escopo_bloco

%%

// Símbolo inicial
raiz: abrir_escopo_global programa fechar_escopo_global
;

programa: program_list   {$$ = $1; arvore = $$; 
                              generateAsm(arvore);
                         }
     |   /*Vazio*/       {$$ = NULL; arvore = NULL; }
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
element: decl_global  {$$ = $1;} 

        | func {$$ = $1;}
;
ident_decl: TK_IDENTIFICADOR  {$$ = createNodo($1);
                              $$->valor_lexico->tipo = INT;
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);
                              //imprimeUltimaTabelaDaPilha(pilha);
                              }
;

// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis globais
decl_global: type id_list_gl ','             {$$ = $1;
                                             $2->valor_lexico->natureza = GLOBAL_DECL;
                                             addFilho($$,$2);
                                             } 
;

// Lista de identificadores
id_list_gl: ident_decl ';' id_list_gl{if($1 == NULL) 
                                      {$$ = $3;}
                                       else
                                        { 
                                        if($3 == NULL) {$$ = $1;}                   
                                            else
                                              {$1->valor_lexico->natureza = GLOBAL_DECL; 
                                               $$ = $1; addFilho($$,$3);}
                                        }    
                                     }
     | ident_decl                  {$1->valor_lexico->natureza = GLOBAL_DECL;
                                   $$ = $1;}                
     ;
// Tipos
type: TK_PR_INT     {$1->tipo = INT;
                     $1->natureza = TYPE;
                     $$ = createNodo($1);
                    } //vai ser sempre int         
     | TK_PR_FLOAT {$1->tipo = INT;
                     $1->natureza = TYPE;
                     $$ = createNodo($1);
                    } //nao importa, vai ser sempre int          
     | TK_PR_BOOL  {$1->tipo = INT;
                     $1->natureza = TYPE;
                     $$ = createNodo($1);
                    } //nao importa, vai ser sempre int        
     ;
// Função => cabeçalho e corpo
// OBS: >>CABEÇALHOS<< FICAM NO ESCOPO GLOBAL
func: header body fechar_escopo_funcao {
                    if($1 != NULL)
                         addFilho($1,$2);
                    $$ = $1;
                    }
     ;
// Cabeçalho => Parâmetros OR Tipo / Identificador
header:  '(' params_list_void ')' TK_OC_OR type '/' ident_func { 
                                                            insereValorLexicoNoTopoDaPilha(pilha, $7->valor_lexico);
                                                            //imprimeUltimaTabelaDaPilha(pilha);
                                                            } abrir_escopo_funcao  {$$ = $7;}
;

ident_func: TK_IDENTIFICADOR 
     { $$ = createNodo($1);
     $$->valor_lexico->tipo = INT;
     $$->valor_lexico->natureza = FUNCTION;
     }
     ;

// Params: Tipo e lista de parâmetros
params_list_void: params_list {$$ = NULL;} 
     | {$$=NULL;}                       
     ;
params_list: param ';' params_list {if($1 == NULL) 
                                      {$$ = $3;}
                                       else
                                        { 
                                        if($3 == NULL) {$$ = $1;}                   
                                            else
                                              {$$ = $1; addFilho($$,$3);}
                                        }    
                                     }
    | param {$$=$1;}
     ;
param: type ident_param {$$ = $2;}
     ;
ident_param: TK_IDENTIFICADOR {$$ = createNodo($1);
     $$->valor_lexico->tipo = INT;
     $$->valor_lexico->natureza = VARIABLE;}
;

// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block                               {$$ = $1;}
     ;
// Aceita bloco com comando vazio 
command_block: '{''}'                         {$$ = NULL;}
     | '{' abrir_escopo_bloco command_list fechar_escopo_bloco '}'           {$$ = $3;}
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

//Declaração de variáveis locais
decl_local: type id_list_lc                 {$$ = $1;
                                             $2->valor_lexico->natureza = VARIABLE;
                                             
                                             //imprimeUltimaTabelaDaPilha(pilha);
                                             addFilho($$,$2);
                                             } 
     ;
id_list_lc: ident_decl ';' id_list_lc   {if($1 == NULL) 
                                             {$$ = $3;}
                                             else
                                                  { 
                                                  if($3 == NULL) {$$ = $1;}                   
                                                  else
                                                       {$1->valor_lexico->natureza = VARIABLE; 
                                                       $$ = $1; addFilho($$,$3);}
                                             } 
                                        }
     | ident_decl                  {$1->valor_lexico->natureza = VARIABLE;
                                   $$ = $1;}                
     ;

// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr     {$$ = createNodo($2);
                                    $1->tipo = INT;
                                    $1->natureza = ATRIBUITION;
                                    addFilho($$, createNodo($1));
                                    addFilho($$, $3);
                                   }
     ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')'   {$1->tipo = INT;
                                             $1->natureza = FUNCTION_CALL;
                                            $$ = createFcallNodo($1);
                                            addFilho($$,$3);
                                             }
     ;

args_list: expr  ';' args_list               {$$ = $1;
                                             addFilho($$, $3);}
     | expr                                  {$$ = $1;}
     ;
// Retorno
return: TK_PR_RETURN expr     {$1->tipo = INT;
                              $1->natureza = RETURN;
                              $$ = createNodo($1);
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

//Expressao
expr: expr8                   {$$ = $1;}
     |                        {$$ = NULL;}
     ;
expr8: expr8 TK_OC_OR expr7   {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);

                              }
     | expr7                  {$$ = $1;}
     ;
expr7: expr7 TK_OC_AND expr6  {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr6                  {$$ = $1;}
     ;
expr6: expr6 TK_OC_EQ expr5   {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr6 TK_OC_NE expr5   {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5                  {$$ = $1;}
     ;
expr5: expr5 '<' expr4        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 '>' expr4        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 TK_OC_LE expr4   {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr5 TK_OC_GE expr4   {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr4                  {$$ = $1;}
     ;
expr4: expr4 '+' expr3        {$$ = createNodo($2);                           
                               $$->valor_lexico->natureza = OPERATOR;                       
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr4 '-' expr3        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr3                  {$$ = $1;}
     ;
expr3: expr3 '*' expr2        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);                            
                              }
     | expr3 '/' expr2        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr3 '%' expr2        {$$ = createNodo($2);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $1);
                               addFilho($$, $3);
                              }
     | expr2                  {$$ = $1;}
     ;
expr2: '-' expr2              {$$ = createNodo($1);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $2);
                              }
     | '!' expr2              {$$ = createNodo($1);
                               $$->valor_lexico->natureza = OPERATOR;
                               addFilho($$, $2);
                              }
     | expr1                  {$$ = $1;}
     ;
expr1: '(' expr ')'           {$$ = $2;}
     | expr0                  {$$ = $1;}
     ;
expr0: operand                {$$ = $1;}
     ;

operand: TK_IDENTIFICADOR     {$$ = createNodo($1);
                              $$->valor_lexico->natureza = OPERAND;
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);}
     | literal                {$$ = $1;
                              $$->valor_lexico->natureza = LITERAL;}
     | fcall                  {$$ = $1;}
     ;
literal: TK_LIT_INT           {$1->natureza = LITERAL;
                              $$ = createNodo($1);
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);}
     | TK_LIT_FLOAT           {$1->natureza = LITERAL;
                              $$ = createNodo($1);
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);}
     | TK_LIT_FALSE           {$1->natureza = LITERAL;
                              $$ = createNodo($1);
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);}
     | TK_LIT_TRUE            {$1->natureza = LITERAL;
                              $$ = createNodo($1);
                              insereValorLexicoNoTopoDaPilha(pilha, $$->valor_lexico);}
     ;

abrir_escopo_global:  /*Vazio*/    { $$ = NULL;
                                     tabela = criaTabela();
                                     pilha = criaPilha();
                                     pushTabelaNaPilha(pilha, tabela);
                                   }
;
fechar_escopo_global: /*Vazio*/    { $$ = NULL;
                                     popTabelaNaPilha(pilha);
                                   }
;
abrir_escopo_funcao:  /*Vazio*/    { $$ = NULL;
                                     tabela = criaTabela();
                                     pushTabelaNaPilha(pilha, tabela);
                                   }
;
fechar_escopo_funcao: /*Vazio*/    { $$ = NULL;
                                     popTabelaNaPilha(pilha);
                                   }
;
abrir_escopo_bloco:  /*Vazio*/     { $$ = NULL;
                                     tabela = criaTabela();
                                     pushTabelaNaPilha(pilha, tabela);
                                   }
;
fechar_escopo_bloco: /*Vazio*/     { $$ = NULL;
                                     popTabelaNaPilha(pilha);
                                   }
;

%%
