#include<stdio.h>
#include<stdlib.h>
typedef struct sjf
{
	int at,bt,st,ct,tat,wt,pr;
}sjf;
void sort(sjf a[],int n)
{ 
	sjf temp;
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
	sjf x[100];
	int n;
	printf("Enter the No of process\n");
	scanf("%d",&n);
	printf("Enter the AT and Bt");
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i].at,&x[i].bt);
		x[i].pr=i;
		x[i].ct=0;
	}
	sort(x,n);
	int com=0,min_bt=0,min_idx=0,time=0;
	while(com<n)
	{
		min_bt=9999;
		min_idx=-1;
		for(int i=0;i<n;i++)
		{
			if(x[i].at<=time&&x[i].ct==0&&x[i].bt<min_bt)
			{
				min_bt=x[i].bt;
				min_idx=i;
				printf("%d\n",time);
			    printf("%d\n",min_bt);
			    printf("%d\n",min_idx);
			}
		}
		if(min_idx!=-1)
		{
			x[min_idx].st=time;
			x[min_idx].ct=time+x[min_idx].bt;
			x[min_idx].tat=x[min_idx].ct-x[min_idx].at;
			x[min_idx].wt=x[min_idx].st-x[min_idx].at;
			com++;
			time=time+x[min_idx].bt;
		}
		else
		{
			printf("%d\n",time);
			printf("%d\n",min_bt);
			printf("%d\n",min_idx);
			time++;
		}
	}
	printf("\nP\tAT\tBT\tST\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x[i].pr,x[i].at,x[i].bt,x[i].st,x[i].ct,x[i].tat,x[i].wt);
	}
	return 0;
}
	

