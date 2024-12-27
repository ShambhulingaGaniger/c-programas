%{
#include<stdio.h>
int flag=0;
int yylex(void);
void yyerror(char*s);
%}

%token SCANF_S STRING CAMMA  AND NAME CP SEMI

%% 
str:SCANF_S STRING CAMMA AND NAME CP SEMI  {flag=1;};


%%
void yyerror(char *s)
{
printf("error");

}
int main()
{
printf("Enter the Input:");
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



