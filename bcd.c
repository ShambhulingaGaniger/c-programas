#include<stdio.h>
#include<math.h>
int main()
{
	int sum=0,bin,count=0;
	printf("enter the number \n");
	scanf("%d",&bin);
	while(bin!=0)
	{
		int a=bin%10;
		sum+=a*pow(2,count++);
		bin=bin/10;
	}
	printf("%d",sum);
	int sum1=0;
	while(sum!=0)
	{
		int a=sum%2;
		sum1=sum1*10+a;
		sum/=2;
	}
	printf("%d",sum1);	
	return 0;
}
