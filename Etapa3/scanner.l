%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342  */
#include <stdio.h>
#include "arvore.h"
#include "valor_lexico.h"
#include "parser.tab.h"


%}
%option   noyywrap
%option   yylineno

%x comment

numero    [0-9]
id        [a-z_][a-z_0-9]*
%%

"int"             {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_INT;}
"float"           {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_FLOAT;}
"bool"            {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_BOOL;}
"if"              {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_IF;}
"else"            {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_ELSE;}
"while"           {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_WHILE;}
"return"          {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_PR_RETURN;}

"false"           {yylval.valor_lexico = createValorLexico(yytext, LITERAL, yylineno); return TK_LIT_FALSE;}
"true"            {yylval.valor_lexico = createValorLexico(yytext, LITERAL, yylineno); return TK_LIT_TRUE;}

{id}              {yylval.valor_lexico = createValorLexico(yytext, IDENTIFICADOR, yylineno); return TK_IDENTIFICADOR;}  

{numero}*"."{numero}+    {yylval.valor_lexico = createValorLexico(yytext, LITERAL, yylineno); return TK_LIT_FLOAT;}
{numero}+                {yylval.valor_lexico = createValorLexico(yytext, LITERAL, yylineno); return TK_LIT_INT;}

"<="              {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_LE;}
">="              {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_GE;}
"=="              {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_EQ;}
"!="              {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_NE;}
"&"               {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_AND;}
"|"               {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return TK_OC_OR;}

"//".*

[-,;(){}+*/%<>|~=!] {yylval.valor_lexico = createValorLexico(yytext, OUTRO, yylineno); return yytext[0];}
[ \t\n]

"/*"               BEGIN(comment);

.                  {return TK_ERRO;}

<comment>[^*]*
<comment>"/*"
<comment>"*"+[^*/]*
<comment>"*"+"/"  BEGIN(INITIAL);

%%

int get_line_number()
{
  return yylineno;
}
void yyerror (char const *mensagem)
{
    fprintf(stderr, "%s",mensagem);
    fprintf(stderr,"\nSyntax error at line %d.",get_line_number());
    fprintf(stderr,"\nToken %s\n",yytext);
}