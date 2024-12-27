#include<stdio.h>
#include<stdlib.h>
#include"QUEUELLADT.h"
void printdatata(void *dp)
{
    printf("%f\n",*(float*)dp);
}
int main()
{
    float*fp;
    int ch,count;
    bool result;
    queue *q;
    q=creatqueue();
    if(!q)
    {
        printf("queue creation is failed\n");
        return 0;
    }
    while(1)
    {
        printf("enter the choice \n1)Enqueue\n2)dqueue\n3)retiev_front\n4)retiev_rear\n5)queuefull\n6)queueemty\n7)count\n8)display\n9)destroy\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:fp=(float*)malloc(sizeof(float));
                  printf("Enter the floating point number \n");
                  scanf("%f",fp);
                  result=Enqueu(q,fp);
                  result==true?printf("succesec\n"):printf("not succesec\n");
                  break;
            case 2:fp=(float*)dequeue(q);
                   if(fp)
                   {
                    printf("dequeue eliment is %f",*fp);
                    free(fp);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
            case 3:fp=(float*)Retrival_front(q);
                  if(fp)
                   {
                    printf("retivrl front eliment is %f",*fp);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
        case 4:    fp=(float*)Retrival_rear(q);
                  if(fp)
                   {
                    printf("retivrl front eliment is %f",*fp);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
        case 5: if(qfull())
                   {
                 printf("queue is full \n");
                  }
                  else 
                  {
                  printf("queue is not full \n");
                  }
                  break;
        case 6: if(qempty(q))
                   {
                 printf("queue is empty \n");
                  }
                  else 
                  {
                  printf("queue is not empty \n");
                  }
                  break;
        case 7:printf("queue coun is %d",qcount(q));
               break;
        case 8:qdisplay(q,printdatata);
                break;
        case 9: qdestroy(q);
                break;
        default:printf("invalid choice \n");
              break;
        }
        

        
        
    }
    return 0;
}
