#include<stdio.h>
void serch(int y[],int x,int i);
int main()
{
	int a[]={10,11,34,56,89,101,132};
	int size=7;
	int x;
	printf("enter the key eliment \n");
	scanf("%d",&x);
	serch(a,x,size);
}
void serch(int y[],int x,int i)
{
	if(i==-1)
	{
		printf("%d elimneb is not pracent \n",x);
		return;
	}
	if(y[i]=x)
	{
		printf("%d elimneb is  pracent \n",x);
		return;
	}
	serch(y,x,i-1);
	
}
