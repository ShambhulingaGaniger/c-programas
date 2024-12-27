#include<stdio.h>
#include<stdlib.h>
#include"QUEUELLADT.h"
void printdata(void *dp)
{
    printf("%d",*(int*)dp);
}
int main()
{
    queue *cat1,*cat2,*cat3,*cat4;
    int x;
    cat1=creatqueue();
    cat2=creatqueue();
    cat3=creatqueue();
    cat4=creatqueue();
    printf("enter the number if sufficen then enter the <EOF>\n");
    while(scanf("%d",&x)!=EOF)
    {
    	int *dp=(int*)malloc(sizeof(int));
    	dp=&x;
        if(x<10)
        {
            bool res=Enqueu(cat1,dp);
        }
        else if(x>9&&x<=20)
        {
              bool res=Enqueu(cat2,dp);
        }
        else if(x>20&&x<=30)
        {
              bool res=Enqueu(cat3,dp);
        }
        else 
        {
              bool res=Enqueu(cat4,dp);
        } 
        free(dp);
    }
    printf("\ncagery one data\n");
    qdisplay(cat1,&printdata);
    printf("\ncagery two data\n");
    qdisplay(cat2,&printdata);
    printf("\ncagery tree data\n");
    qdisplay(cat3,&printdata);
    printf("\ncagery four data\n");
    qdisplay(cat4,&printdata);
    qdestroy(cat1);
    qdestroy(cat2);
    qdestroy(cat3);
    qdestroy(cat4);
    {

    }
}