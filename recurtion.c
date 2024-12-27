#include<stdio.h>
void serch(int y[],int x,int first,int last);
int main()
{
	int a[]={10,11,34,56,89,101,132};
	int size=7;
	int x;
	printf("enter the key eliment \n");
	serch(a,34,1,7);
}
void serch(int y[],int x,int first,int last)
{
	int mid=(first+last)/2;
		if(y[mid]==x)
	{
		printf("%d eliment is pracent \n",x);
		return ;
	}
	if(first>last)
	{
		printf("%d eliment is not pracent \n",x);
		return ;
	}

	if(y[mid]>x)
	{
		serch(y,x,first,mid-1);
	}
	else
	  serch(y,x,mid+1,last);
}

