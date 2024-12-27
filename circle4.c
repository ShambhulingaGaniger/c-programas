


#include"ListAdt.h"
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
	list*p;
	int ch;
	node*prev;
	p=creatlist();
	for(int i=0;i<7;i++)
	{
		printf("enter the choice to enter the number1)big\n2)mid\n3)end\n");
		scanf("%d",&ch);
		x=(int*)malloc(sizeof(int));
		switch(ch)
		{
			case 1:prev=NULL;
			       break;
			case 2:printf("enter the prev number\n");
			pre=(int*)malloc(sizeof(int));
			       scanf("%d",pre);
			       prev=serchlist(p,pre,com);
			      if(!prev)
					  printf("serch failed \n");
				  break;
			case 3:prev=p->head;         
						        while(prev->next!=p->head)
						            prev=prev->next;
						        break;
						 default:printf("invalid choice\n");
						         break;
					 }
					 if(ch==2&&prev==NULL)
					      break;
					 printf("ener the data\n");
					 scanf("%d",x);
					 if(circular_i(p,prev,x))
					    printf(" succes\n");
					 else
					   printf("failed");
	 }
	 printf(" poped eliment is %d\n",*(int*)circular_d(p,NULL));
	 
	 printf(" poped eliment is %d\n",*(int*)circular_d(p,NULL));
	 
	 printf(" poped eliment is %d\n",*(int*)circular_d(p,NULL));
	 circular_di(p,printdata);
	 return 0;
 }
 		else if(prev->next==NULL)
		{
			newnode->next=prev->prev;
			newnode->prev=prev;
			prev->next=newnode;
		}
 
