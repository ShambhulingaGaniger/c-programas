%{
#include "while.tab.h"
%}

%%
"while"         return WHILE;
")"             return CP;
"("             return OP;
"{"             return OF;
"}"             return CF;
"&&"            return AND;
"||"            return OR;
"=="            return EQ;
"!="            return EQ;
"<"             return EQ;
">"             return EQ;
"<="            return EQ;
">="            return EQ;
[A-Za-z][A-Za-z0-9]* return ID;
\"[^\"]+\"      return STEM;
[ \t\n]+        ; /* ignore whitespace */
.               return yytext[0]; /* return any other character as is */
%%

int yywrap(void) {
    return 1;
}
