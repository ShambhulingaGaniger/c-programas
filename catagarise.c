#include<stdio.h>
#include<stdlib.h>
#include"qarrayadt.h"
void printdata(void *dp)
{
    printf("%d\n",*(int*)dp);
}
int main()
{
    qarray *cat1,*cat2,*cat3,*cat4;
    int x;
    cat1=creatQ();
    cat2=creatQ();
    cat3=creatQ();
    cat4=creatQ();
    
    printf("enter the number if sufficen then enter the <EOF>\n");
    while(scanf("%d",&x)!=EOF)
    {
        if(x<10)
        {
            if(enqueue(cat1,&x))
			{
				printf("success");
					}        }
        else if(x>9&&x<=20)
        {
        	if(enqueue(cat2,&x))
        	{
				printf("success");
          }
        }
        else if(x>20&&x<=30)
        {
            
             if( enqueue(cat3,&x))
        	{
				printf("success");
          }
        }
        else if(x<30)
        {
             enqueue(cat2,&x);
        } 
    }
    printf("\ncagery one data\n");
    qdisplay(cat1,printdata);
    printf("\ncagery two data\n");
    qdisplay(cat2,printdata);
    printf("\ncagery tree data\n");
    qdisplay(cat3,printdata);
    printf("\ncagery four data\n");
    qdisplay(cat4,printdata);
    qdestroy(cat1);
    qdestroy(cat2);
    qdestroy(cat3);
    qdestroy(cat4);
    
}

