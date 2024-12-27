#include"arraylinkedlist.h"
void printdata(void*dp)
{
	printf("%d \n",*(int*)dp);
}
bool com(void*dp,void*pq)
{
	
	if(*(int*)dp==*(int*)pq)
	{
	     return true;
	     }
	return false;
}
int main()
{
	int *x,*pre;
	alist*p;
	int ch;
	int prev;
	p=creatlist(com,printdata);
	for(int i=0;i<7;i++)
	{
		printf("enter the choice to enter the number1)big\n2)mid\n3)end\n");
		scanf("%d",&ch);
		x=(int*)malloc(sizeof(int));
		switch(ch)
		{
			case 1:prev=p->head;
			       break;
			case 2:printf("enter the prev number\n");
			pre=(int*)malloc(sizeof(int));
			       scanf("%d",pre);
			       prev=serchlist(p,pre);
			      if(!prev)
					  printf("serch failed \n");
				  break;
			case 3:prev=0;         
						       
					 }
					 printf("ener the data\n");
					 scanf("%d",x);
					 if(inserte(x,p,prev))
					    printf(" succes\n");
					 else
					   printf("failed");
	 }
	 printf(" poped eliment is %d\n",*(int*)deletion(p,p->head));
	 
	 printf(" poped eliment is %d\n",*(int*)deletion(p,p->head));
	 printf(" poped eliment is %d\n",*(int*)deletion(p,p->head));
	 disply(p);
	 return 0;
 }
 		
 
