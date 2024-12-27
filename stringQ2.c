#include"qarrayadt.h"
#define SIZEOF 25;
void printdata(void *s)
{
    printf("%s ",(char*)s);
}
int main()
{
    char *str;
    int ch;
    qarray* q;
    bool res;
    q=creatQ();
    if(!q)
    {
        printf("q is not created\n ");
        return 0;
    }
    while(1)
    {
       printf("\nenter the choice \n1)Enqueue\n2)dqueue\n3)retiev_front\n4)retiev_rear\n5)queuefull\n6)queueemty\n7)count\n8)display\n9)destroy\n");
       scanf("%d",&ch);
       switch ((ch))
       {
         case 1:str=(char*)malloc(sizeof(float));
                  printf("Enter the String \n");
                  scanf("%s",str);
                  res=enqueue(q,str);
                  res==true?printf("succesec\n"):printf("not succesec\n");
                  break;
            case 2:str=(char*)dequeue(q);
                   if(str)
                   {
                    printf("dequeue eliment is %s",str);
                    free(str);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
            case 3:str=(char*)r_front(q);
                  if(str)
                   {
                    printf("retivrl front eliment is %s",str);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
        case 4:    str=(char*)r_rear(q);
                  if(str)
                   {
                    printf("retivrl front eliment is %s",str);
                   }
                   else{
                    printf("queue is empty\n");
                   }
                   break;
        case 5: if(qfull(q))
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
        case 8:qdisplay(q,printdata);
                break;
        case 9: qdestroy(q);
                break;
        default:printf("invalid choice \n");
              break;
        }    
    }
    return 0;
}
