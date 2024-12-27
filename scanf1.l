%{
#include"scanf1.tab.h"
#include<stdio.h>
%}

%%
"scanf(" {return SCANF_S;}
\"[%a-z]+\" return STRING;
";" return SEMI;
")" return CP;
"," return CAMMA;
"&" return AND;
[A-Za-z0-9]+ return NAME;

%%
int yywrap()
{
return 1;
}
