#include<stdio.h>
int main()
{
	int sum=4;
	for(int i=5;i<7;i++)
	{
		sum&=i;
	}
	printf("%d",4&5&6&7&8&8);
	printf("%d",sum&6);
	return 0;
}
