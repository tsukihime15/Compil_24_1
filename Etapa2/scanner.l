%{
/* Gessica Franciéle Mendonça Azevedo - 00302865 | Jéssica Maria Lorencetti - 00228342  */
#include "parser.tab.h"

%}
%option   noyywrap
%option   yylineno

%x comment

numero    [0-9]
id        [a-z_][a-z_0-9]*
%%

"int"             {return TK_PR_INT;}
"float"           {return TK_PR_FLOAT;}
"bool"            {return TK_PR_BOOL;}
"if"              {return TK_PR_IF;}
"else"            {return TK_PR_ELSE;}
"while"           {return TK_PR_WHILE;}
"return"          {return TK_PR_RETURN;}

"false"           {return TK_LIT_FALSE;}
"true"            {return TK_LIT_TRUE;}

{id}              {return TK_IDENTIFICADOR;}  

{numero}*"."{numero}+    {return TK_LIT_FLOAT;}
{numero}+                {return TK_LIT_INT;}

"<="              {return TK_OC_LE;}
">="              {return TK_OC_GE;}
"=="              {return TK_OC_EQ;}
"!="              {return TK_OC_NE;}
"&"               {return TK_OC_AND;}
"|"               {return TK_OC_OR;}

"//".*

[-,;(){}+*/%<>|&~=\[\]] {return yytext[0];}
[ \t\n]

"/*"               BEGIN(comment);

.                  {return TK_ERRO;}

<comment>[^*\n]*
<comment>"/*"
<comment>"*"+[^*/\n]*
<comment>"*"+"/"  BEGIN(INITIAL);

%%

int get_line_number()
{
  return yylineno;
}
