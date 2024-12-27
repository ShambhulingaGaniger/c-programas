#include<stdio.h>
int  serch(int y[],int j,int i);
int main()
{
	int a[]={10,11,11,34,56,89,11,101,11,132,56};
	int size=11;
	int x;
	printf("enter the key eliment \n");
	scanf("%d",&x);
	printf("%d",serch(a,x,size));
}
int serch(int y[],int j,int i)
{
	if(i==-1)
	{
		return 0;
	}
	if(y[i]==j)
	{
	  return 1+serch(y,j,i-1);
	}
	return 0+serch(y,j,i-1);
}

