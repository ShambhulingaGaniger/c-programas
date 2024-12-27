%{
#include <stdio.h>
void yyerror(char *s);
int yylex(void);
int flag = 0;
%}

%token WHILE OP CP OF CF STEM ID AND OR EQ

%%

statement: WHILE OP condition CP OF statement_body CF { flag = 1; };

condition: ID EQ ID
         | ID EQ ID AND condition
         | ID EQ ID OR condition
         | OP condition CP
         ;

statement_body: STEM
              | STEM statement_body
              | statement
              | statement statement_body
              ;

%%

void yyerror(char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter the Input: ");
    yyparse();
    if (flag == 1) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}
