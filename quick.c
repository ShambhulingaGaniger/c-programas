#include<stdio.h>
int par(int x[],int l,int m)
{
	int piv=x[l];
	int st=l,en=m,temp;
	while(st<en)
	{
		while(x[st]<=piv)
		{
			st++;
		}
		while(x[en]>piv)
		{
			en--;
		}
		if(st<en)
		{
			temp=x[st];
			x[st]=x[en];
			x[en]=temp;
		}
		    
	}
	temp=x[l];
	x[l]=x[en];
	x[en]=temp;
	return en;
}
void quick(int x[],int a,int b)
{
	if(a<b)
	{
		int loc=par(x,a,b);
		quick(x,a,loc-1);
		quick(x,loc+1,b);
	}
}
		
int main()
{
	int x[]={3,6,4,7,1,10,9,4};
	quick(x,0,7);
	for(int i=0;i<8;i++)
	{
		printf("%d",x[i]);
	}
	return 0;
}
