#include<stdio.h>
int serch(int x);
int main()
{
	int x;
	printf("enter the key eliment \n");
	scanf("%d",&x);
	printf("%d",serch(x));
}
int serch(int x)
{
	if(x==0)
	{
		return 0;
	}
	return ((x%10)+serch(x/10));
}

