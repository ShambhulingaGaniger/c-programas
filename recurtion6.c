#include<stdio.h>
#include<string.h>
char* rep(char *ch,char*st,int i,int j)
{
	if(ch[j]=='\0')
	{
		return;
	}
	if(ch[i]!=' ')
	  st[j++]=ch[i];
	return rep(ch,st,++i,j);
}
int main()
{
	char *ch;
	ch= (char*)calloc(20,sizeof(char));
	char *st=(char*)calloc(20,sizeof(char));
	printf("string enter \n");
	scanf("%s",ch);
	st=rep(ch,st,0,0);
	printf("%s",st);
}
