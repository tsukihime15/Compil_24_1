%{
#include "tokens.h"

int lineNumber = 1;
%}
%%

"int"      {return TK_PR_INT;}

%%

int get_line_number()
{
  return lineNumber;
}
