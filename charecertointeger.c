#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"linklistadt.h"
int priority(char token);
bool isoperater(char token);
int calcul(int opn1,int opn2,char token)
{
	switch(token)
	{
		case '+':return opn1+opn2;
		case '-':return opn1-opn2;
		case '*':return opn1*opn2;
		case '/':return opn1/opn2;
	}
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
int main()
{
	int opn1,opn2,result,i=0;
	char ch[25],token;
	stack *head;
	bool res;
	int *pd;
	printf("enter the posfix eliment \n");
	scanf("%s",ch);
	head=createstack();
	while(ch[i]!='\0')
	{
		token=ch[i];
		if(isoperater(token))
		{
			pd=(int*)popstack(head);
			opn2=*pd;
			free(pd);
			pd=(int*)popstack(head);
			opn1=*pd;
			result=calcul(opn1,opn2,token);
			*pd=result;
			res=pushstack(head,pd);
		}
		else
		{
			pd=(int*)malloc(sizeof(int));
			*pd=token-'0';
			res=pushstack(head,pd);
		}
		i++;
	}
	pd=(int*)popstack(head);
	printf("%d",*pd);
	free(pd);
	return 0;
}
