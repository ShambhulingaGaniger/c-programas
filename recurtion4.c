#include<stdio.h>
int search(int x[10][10],int i,int j,int a);
int main()
{
	int x[10][10];
	int i,j,a,b;
	printf("enter the size of the array\n");
	scanf("%d%d",&i,&j);
	printf("enter the size of the eliment\n");
	for( a=0;a<i;a++)
	{
		for( b=0;b<j;b++ )
		{
			scanf("%d",&x[a][b]);
		}
	}
	printf("%d",search(x,i-1,j-1,j-1));
}
int search(int x[10][10],int i,int j,int a)
{
	if(i<0)
   	 return 0;
    if(j<0)
	 return search(x,--i,a,a);
    return x[i][j]+search(x,i,j-1,a);
	
}

