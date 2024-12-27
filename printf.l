%{
#include"printf.tab.h"
%}

%%
"printf(" {return PRINTF_S;}
[\t]  {}
[\n]  {return 0;}
[A-Za-z0-9]+  {return NAME;}
\"[^\"]*\"  {return STRING;}
")" {return')';}
";" {return';';}
","  {return',';}
.  {}
%%
int yywrap()
{
return 1;
}
