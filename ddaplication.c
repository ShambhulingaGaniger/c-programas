#include"doublecir.h"
#include"ListAdt.h"
void printdata(void*dp)
{
	printf("%d\n",*(int*)dp);
}
bool com(void*dp,void*si)
{
	if(*(int*)dp==*(int*)si)
	    return true;
	return false;
}
int main()
{
	int*x;
	dll*p=creatdlistd();
	dnode*prev;
	for(int i=0;i<9;i++)
	{
		x=(int*)malloc(sizeof(int));
		printf("ener the number\n");
		scanf("%d",x);
		
		if(inseriondd(p,NULL,x))
		{
			printf("succes");
		}
		else
		  printf("not s\n");
	  }
	  prev=p->head;
	  while(prev->next)
		   prev=prev->next;
	  if(inseriondd(p,prev,x))
		{
			printf("succes");
		}
		else
		  printf("not s\n");
	  
	  printf("%d\n",*(int*)deletiondd(p,NULL));
	  printf("%d\n",*(int*)deletiondd(p,NULL));
	  printf("%d\n",*(int*)deletiondd(p,NULL));
	  dlldisplay(p,printdata);
	  return 0;
  }
	  
