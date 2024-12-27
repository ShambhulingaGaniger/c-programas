#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct  Double
{
    void **dp;
    int count,front,size,rear;
}DP;
bool qempty(DP*q)
{
    if(q->count==0)
    {
        return true;
    }
    return false;

}
bool qfull(DP*q)
{
    if(q->count==q->size)
    {
        return true;
    }
    return false;
}
DP* creataQ()
{
    DP *q;
    q=(DP*)malloc(sizeof(DP));
    printf("enter size of the Q\n");
    scanf("%d",&q->size);
    q->dp=(void**)calloc(q->size,sizeof(void));
    if(q)
    {
        q->front=q->size-1;
        q->rear=q->size-1;
        q->count=0;
        return q;
    }
    return NULL;
}
bool enqueue_front(DP*q,void *dp)
{
    if(qfull(q))
    {
        return false;
    }
    if(qempty(q))
    {
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front--;
        if(q->front<0)
        {
            q->front=q->size-1;
        }
    }
    q->dp[q->front]=dp;
    q->count++;
    return true;
}
void* dqueu_rear(DP*q)
{
 void *dp;
 if(qempty(q))
 {
    return NULL;
 }
 dp=q->dp[q->rear];
 q->count--;
 if(q->count==0)
 {
    q->front=-1;
    q->rear=-1;
 }
 q->rear--;
 return dp;
}
int main()
{
    DP*q;
    int*dp;
    int ch;
    q=creataQ();
    if(!q)
    {
        printf("Q not created\n");
        return 0;
    }
    while(1)
    {
        printf("\nenter the choice\n 1)enqueue_front\n2)dqueu_rear");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:dp=(int*)malloc(sizeof(int));
               printf("enter the number\n");
               scanf("%d",dp);
               bool res=enqueue_front(q,dp);
               res==true?printf("success\n"):printf("not success\n");
            break;
        case 2:while(!qempty(q))
              {
              	int *dp=(int*)malloc(sizeof(int));
              	if(dp)
				  dp=(int*)dqueu_rear(q);
                printf("%d",*dp);
                free(dp);
              }
              break;
        default:
            break;
        }
    }
}


