%{
#include<stdio.h>
#include<stdlib.h>
int flag=0;
int yylex(void);
void yyerror(char*);
%}

%token PRINTF_S STRING ',' NAME ';' 

%%
string:PRINTF_S STRING ',' NAME ')' ';' {flag=1;}
|PRINTF_S STRING  ')' ';' {flag=1;}
%%
void yyerror(char *s)
{
printf("error");

}
int main()
{
printf("Eenter the Input:");
yyparse();
if(flag==1)
{
printf("valid");
}
else
{
printf("invalid");
}return 0;
}
