#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"linklistadt.h"
int priority(char token);
bool isoperater(char token);
int main() {
    char postfix[25], token;
    char *dp;
    stack *head;
    int i = 0;
    head = createstack();
    printf("Enter the infix: ");
    while ((token = getchar()) != '\n') {
        if (token == '(') {
            dp = (char *)malloc(sizeof(char));
            *dp = token;
            bool res = pushstack(head, dp);
        } else if (!stackempty(head)&&token == ')') {
            dp = (char *)popstack(head);
            while (*dp != '(') {
                postfix[i++] = *dp;
                free(dp);
                dp = (char *)popstack(head);
            }
            free(dp); // Free the '('
        } else if (isoperator(token)) 
		{ 
		       if(!stackempty)
			   {
				*dp=token;
				bool res=pushstack(head,dp);
			   }
            dp = (char *)stacktop(head);
            while (!stackempty(head) && priority(token) <= priority(*(char *)dp)) {
                dp = (char *)popstack(head);
                postfix[i++] = *(char *)dp;
                free(dp);
                dp = (char *)stacktop(head);
            }
            dp = (char *)malloc(sizeof(char));
            *dp = token;
            bool res = pushstack(head, dp);
        } else {
            postfix[i++] = token;
        }
    }
    while (!stackempty(head)) {
        dp = (char *)popstack(head);
        postfix[i++] = *(char *)dp;
        free(dp);
    }
    postfix[i++] = '\0';
    printf("Postfix of the infix is: %s\n", postfix);
    stackdestroy(head);
    return 0;
}
bool isoperater(char token)
{
	switch(token)
	{
		case '+':
		case '-':
		case '*':
		case '/':return true;
	}
	return false;
}
int priority(char token)

{
	switch(token)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
	}
}