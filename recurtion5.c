#include<stdio.h>
void rev(int x[],int i,int j);
int main()
{
	int a[]={10,11,12,13,14,15,16};
	rev(a,0,6);
	int x=0;
	for(x=0;x<7;x++)
	{
		printf("%d ",a[x]);
	}
}
void rev(int x[],int i,int j)
{
	if(i>j)
	{
		return ;
	}
	int temp;
	temp=x[i];
	x[i]=x[j];
	x[j]=temp;
	rev(x,i+1,--j);
	int a=0;
	
	
}
