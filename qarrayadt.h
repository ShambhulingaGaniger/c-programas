#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct qarrayadt
{
    void **qd;
    int front,rear,count,size;
}qarray;
bool qempty(qarray*q)
{
    if(q->count==0)
    {
        return true;
    }
    return false;

}
bool qfull(qarray*q)
{
    if(q->count==q->size)
    {
        return true;
    }
    return false;
}
qarray* creatQ()
{
    qarray *q;
    q=(qarray*)malloc(sizeof(qarray));
    if(q)
    {
        printf("enetr the size of the Q \n");
        scanf("%d",&q->size);
        q->qd=(void**)calloc(q->size,sizeof(void*));
        q->front=-1;
        q->rear=-1;
        q->count=0;
        return q;
    }
    return NULL;
}
 bool enqueue(qarray *q,void *dp)
{
    if(qfull(q))
    {
        return false;
    }
    else if(qempty(q))
    {
        q->front=0;
    }
    q->rear=(q->rear+1)%q->size;
    q->qd[q->rear]=dp;
    q->count++;
    return true;
}
void *dequeue(qarray *q)
{
    void *dp;
    if(qempty(q))
    {
        return NULL;
    }
    dp=q->qd[q->front];
    q->front=(q->front+1)%q->size;
    q->count--;
    return dp;
}
void *r_front(qarray*q)
{
    if(qempty(q))
    {
        return NULL;
    }
    return q->qd[q->front];
}
void *r_rear(qarray*q)
{
    if(qempty(q))
    {
        return NULL;
    }
    return q->qd[q->rear];
}

void qdisplay(qarray *q, void (*pf)(void *))
{
    if (qempty(q))
    {
        printf("queue is empty\n");
        return;
    }

    int temp;
    for (temp = q->front; temp != (q->rear + 1) % q->size; temp = (temp + 1) % q->size)
    {
        pf(q->qd[temp]);
    }
}

void qdestroy(qarray*q)
{
    int temp,i=0;
    if(!q)
    {
        printf("q is empty\n");
        return ;
    }
    for(temp=q->front;temp!=q->rear;temp=(temp+1)%q->size)
    {
        free(q->qd[temp]);
    }
    printf("hello\n");
    free(q->qd);
    free(q);
}
int qcount(qarray*q)
{
	return q->count;
}


