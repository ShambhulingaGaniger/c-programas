#include<stdio.h>
typedef struct fafs
{
	int at,bt,st,ct,tat,wt,pr;
}fafs;
void sort(fafs a[],int n)
{ 
	fafs temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].at>a[j].at)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int main()
{
	fafs x[100];
	int n;
	printf("Enter the No of process\n");
	scanf("%d",&n);
	printf("Enter the AT and Bt");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i].at,&x[i].bt);
		x[i].pr=i;
	}
	sort(x,n);
	x[0].ct=x[0].bt;
	x[0].st=x[0].at;
	for(int i=1;i<n;i++)
	{
		if(x[i].at>x[i-1].ct)
		{
			x[i].st=x[i].at;
			x[i].ct=x[i].at+x[i].bt;
		}
		else
		{
			x[i].st=x[i-1].ct;
			x[i].ct=x[i].st+x[i].bt;
		}
		printf("->[p%d] start=%d complit=%d",x[i].pr,x[i].at,x[i].ct);
		x[i].tat=x[i].ct-x[i].at;
		x[i].wt=x[i].tat-x[i].bt;
	}
	printf("\nP\tAT\tBT\tST\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x[i].pr,x[i].at,x[i].bt,x[i].st,x[i].ct,x[i].tat,x[i].wt);
	}
	return 0;
}

