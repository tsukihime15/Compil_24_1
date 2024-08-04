%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342 | Mariana Koppe - 00219819 */
#include <stdio.h>
#include "arvore.h"
#include "valor_lexico.h"
#include "funcoes.h"

int yylex(void);
int yyparse(void);
extern void yyerror (char const *mensagem);

extern void* arvore;
extern Lista_tabelas *lista_tabelas;
extern Tabela *tabela_global;
extern Tabela *tabela_escopo;
extern int tipo_atual;

%}

// %code requires
// {
//     #include "arvore.h"   
//     #include "valor_lexico.h"
//     #include "funcoes.h"
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
%type<nodo> element
%type<nodo> ident_func
%type<nodo> ident_decl
%type<nodo> ident_param
%type<nodo> func
%type<nodo> type
%type<nodo> decl_global
%type<nodo> decl_local
%type<nodo> id_global
%type<novo> id_local
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
programa: program_list               {
     $$ = $1; arvore = $$;
          imprimeInstrucoesNodo($$);
          popTabela(&lista_tabelas);
};                      
programa:                            {$$ = NULL; arvore = NULL;
          
 }
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
element: decl_global  { // Declaracoes nao sao usadas nessa etapa

        | func {$$ = $1;}
};
ident_decl: TK_IDENTIFICADOR {$$ = createNodo($1);}
;
// Variáveis globais => Tipo e Lista de identificadores
// Declaração de variáveis globais
decl_global: type { tipo_atual = verificaTipo($1->valor_token); } id_global ','   // Declaracoes nao sao usadas nessa etapa
;
id_global: TK_IDENTIFICADOR ',' id_global //lista de declaração global 	
{ 
	$1->tipo_token = tipo_atual; 
	$1->tamanho_token = infereTamanho(tipo_atual); 
	verificaERR_DECLARED(lista_tabelas,$1); 
	insereUltimaTabela(&lista_tabelas, $1); 
};

id_global:  TK_IDENTIFICADOR						
{ 
	$1->tipo_token = tipo_atual; 
	$1->tamanho_token = infereTamanho(tipo_atual); 
	verificaERR_DECLARED(lista_tabelas,$1); 
	insereUltimaTabela(&lista_tabelas, $1);
};


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
func: header body                            {$$ = $1;
                                              addFilho($$,$2);}
     ;
// Cabeçalho => Parâmetros OR Tipo / Identificador
//não sei se está certo a função, favor verificar
header: '(' push_tabela_escopo params_list_void ')' TK_OC_OR type  {

     tipo_atual = verificaTipo($6->valor_token);
	$2->tipo_token = tipo_atual;
	$2->natureza_token = FUNCTION;
	$2->tamanho_token = infereTamanho(tipo_atual);
		
	verificaERR_DECLARED(lista_tabelas,$2);
	insereEntradaTabela(&(lista_tabelas->tabela_simbolos), $2);
     
     }
;
ident_func: TK_IDENTIFICADOR  {$$ = createNodo($1);}

// Params: Tipo e lista de parâmetros
params_list_void: params_list {$$ = $1;} //parametros nao criam nodos nem sao filhos
     | {$$=NULL;}                       
     ;
params_list: param ';' params_list { $$ = $1; adicionaNodo($$, $3);}//parametros nao criam nodos nem sao filhos
    | param {$$=NULL;} //verificar a necessidade do NULL
     ;
param: type ident_param {$$=NULL;}//parametros nao criam nodos nem sao filhos
     ;
ident_param: TK_IDENTIFICADOR {
     $$ = criaNodo($1); 
     }
     ;

// Bloco de comandos (corpo) => Declaração de var. | Chamada de Atribuição | Chamada de Função | Retorno | Controle de fluxo | outro bloco de comandos
body: command_block      
                         {
     $$ = criaNodo($1);
	if($8 != NULL)
	{
		adicionaNodo($$, $8);
		$$->info->codigo = $8->info->codigo;
	}
}
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
                                                {
                                                $$ = $1; 
                                                addFilho($$,$3);
                                                $$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
                                                }
                                                 }
                                        
                                        }    }
     | simple_command ','                         {$$ = $1;}
     ;

command_list: push_tabela_escopo command_block ',' command_list
{
	if($2 != NULL && $4 != NULL)
	{
		$$ = $2;
		concatenate_list($$, $4);
		$$->info->codigo = concatenaCodigo($2->info->codigo, $4->info->codigo);
	}
	
	else if($2 != NULL)
		$$ = $2;
	
	else if($4 != NULL)
		$$ = $4;

	else
		$$ = NULL;
};
command_list: push_tabela_escopo command_block ',' { $$ = $2; };  
push_tabela_escopo: { pushTabela(&lista_tabelas, tabela_escopo); }

command_list: decl_local ',' command_list
{
	if($1 != NULL && $3 != NULL)
	{
		$$ = $1;
		concatenate_list($$, $3);
		$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
	}
	
	else if($1 != NULL)
		$$ = $1;
		
	else if($3 != NULL)
		$$ = $3;
		
	else
		$$ = NULL;
};

command_list:	decl_local ',' { $$ = $1; };
simple_command: command_block      {$$ = $1;}
     | decl_local                  {$$ = $1;}
     | atr                         {$$ = $1;}
     | fcall                       {$$ = $1;}
     | return                      {$$ = $1;}
     | cflow                       {$$ = $1;}
     ;
decl_local: tipo_local id_list {$$=$2;};

tipo_local: TK_PR_INT    {$$ = NULL;}       
     | TK_PR_FLOAT {$$ = NULL;}         
     | TK_PR_BOOL  {$$ = NULL;} 
     ; 

id_list: id_local {$$=$1;};
id_list:id_local ',' id_list
{
	if($1 != NULL && $3 != NULL)
	{
		$$ = $1;
		addFilho($$, $3);
	}
	
	else if($1 != NULL)
		$$ = $1;
		
	else if($3 != NULL)
		$$ = $3;
		
	else
		$$ = NULL;
};

id_local: TK_IDENTIFICADOR
{ 
	$$ = NULL; 
	$1->tipo_token = tipo_atual;
	$1->tamanho_token = infereTamanho(tipo_atual);
	verificaERR_DECLARED(lista_tabelas, $1);
	insereUltimaTabela(&lista_tabelas, $1); 
};

// Chamada de Atribuição
atr: TK_IDENTIFICADOR '=' expr     {$$ = createNodo($2);
                                    addFilho($$, createNodo($1));
                                    addFilho($$, $3);
                                   }
     ;
// Chamada de Função
fcall: TK_IDENTIFICADOR '(' args_list ')'   {$$ = createFcallNodo($1);
                                              addFilho($$,$3);

                                             }
     ;
// agora aceita argumentos vazio()
args_list: expr  ';' args_list               {$$ = $1;
                                             addFilho($$, $3);}
     | expr                                  {$$ = $1;}
     ;
// Retorno
return: TK_PR_RETURN expr   {$$ = createNodo($1);
                                 addFilho($$,$2);
                                }              
     ;
//nao entendi o q eh pra por, na E3 diz "usar o lexema correspondente como label"
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
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("or",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr7                  {$$ = $1;}
     ;
expr7: expr7 TK_OC_AND expr6  {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               
  	$$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("and",$1->info->temporario,$3->info->temporario,$$->info->temporario));
                              }
     | expr6                  {$$ = $1;}
     ;
expr6: expr6 TK_OC_EQ expr5   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_EQ",$1->info->temporario,$3->info->temporario,$$->info->temporario));
                              }
     | expr6 TK_OC_NE expr5   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_NE",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr5                  {$$ = $1;}
     ;
expr5: expr5 '<' expr4        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_LT",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr5 '>' expr4        {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_GT",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr5 TK_OC_LE expr4   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_LE",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr5 TK_OC_GE expr4   {$$ = createNodo($2);
                               addFilho($$, $1);
                               addFilho($$, $3);
                               $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("cmp_GE",$1->info->temporario,$3->info->temporario,$$->info->temporario));

                              }
     | expr4                  {$$ = $1;}
     ;
expr4: expr4 '+' expr3        
          {$$ = createNodo($2);                           
               addFilho($$, $1);
               addFilho($$, $3);
               //atualizar as funções para as variais do trabalho
          $$->info->temporario = temporario_atual;
  	     temporario_atual++;
  	
  	     $$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	     insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("add",$1->info->temporario,$3->info->temporario,$$->info->temporario));

          }
     | expr4 '-' expr3       
          {$$ = createNodo($2);
               addFilho($$, $1);
               addFilho($$, $3);
          $$->info->temporario = temporario_atual;
  	     temporario_atual++;
  	
  	     $$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	     insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("sub",$1->info->temporario,$3->info->temporario,$$->info->temporario));

          }
     | expr3                  {$$ = $1;}
     //fazer logica de atribuição
     ;
expr3: expr3 '*' expr2        
       {$$ = createNodo($2);
             addFilho($$, $1);
             addFilho($$, $3); 
             $$->info->temporario = temporario_atual;
  	temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("mult",$1->info->temporario,$3->info->temporario,$$->info->temporario));
              
                              }
     | expr3 '/' expr2        
         {$$ = createNodo($2);
               addFilho($$, $1);
               addFilho($$, $3);
               $$->info->temporario = temporario_atual;
  	          temporario_atual++;
  	
  	$$->info->codigo = concatenaCodigo($1->info->codigo, $3->info->codigo);
  	insereInstrucao(&($$->info->codigo), criaInstrucaoAritmeticaLogica("div",$1->info->temporario,$3->info->temporario,$$->info->temporario));
  	
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

/*verificar as chaves pois me confundi*/
operand: TK_IDENTIFICADOR   {  {$$ = createNodo($1);}
     | literal                {$$ = $1;}
     | fcall                  {$$ = $1;}
     verificaERR_UNDECLARED_FUNCTION(lista_tabelas,$1);
	$1->tipo_token = obtemTipo(lista_tabelas,$1);
	$1->tamanho_token = infereTamanho($1->tipo_token);
	
	$1->temporario = temporario_atual;
	temporario_atual++;
	atualizaRegistradorEscopo(lista_tabelas, registrador_escopo, $1->valor_token);
	deslocamento_atual = achaDeslocamento(lista_tabelas,$1->valor_token);
	insereInstrucao(&($$->info->codigo), criaInstrucao_loadAI($1->temporario,registrador_escopo,deslocamento_atual));
}
     ;
literal: TK_LIT_INT           {$$ = createNodo($1);}
     | TK_LIT_FLOAT           {$$ = createNodo($1);}
     | TK_LIT_FALSE           {$$ = createNodo($1);}
     | TK_LIT_TRUE            {$$ = createNodo($1);}
     ;
%%
