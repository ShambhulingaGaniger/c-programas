
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
static int *key;
bool check(void*dp);
void pf(void*dp)
{
	printf("%d",*(int*)dp);
}
bool check(void*dp)
{
  if(*key==*(int*)dp)
  {
    return true;
  }
  return false;
}
typedef struct Node{
    void *dp;
    struct Node *next;
}node;
typedef struct List
{
    int count;
    node *head;
}list;
list *creatll()
{
    list*l;
    l=(list*)malloc(sizeof(list));
    if(!l)
    {
        return NULL;
    }
    l->head=NULL;
    l->count=0;
    return l;
}
bool lempty(list*l)
{
  if(l->count==0)
  {
    return true;
  }
  return false;
}
bool add_first(list*l,void*dp)
{
    node *newnode;
	newnode=(node*)malloc(sizeof(node));
    if(newnode)
    {
        newnode->dp=dp;
        newnode->next=l->head;
        l->head=newnode;
        l->count++;
        return true;
    }
    return false;
}
void* remove_first(list*l)
{
    node*temp;
    void*dp;
    if(l->count==0)
    {
        return NULL;
    }
    temp=l->head;
    l->head=temp->next;
    dp=temp->dp;
    l->count--;
    return dp;
}
bool findingkey(list*l)
{
    if(lempty(l))
    {
        return false;
    }
    node *temp=l->head;
    while(temp!=NULL)
    {    
		bool res=check(temp->dp);
      if(res)
      {
        return true;
      }
      temp=temp->next;
    }
    return false;
}
void*remove_last(list*l)
{
    if(lempty(l))
    {
       return NULL; 
    }
    node*temp1=l->head;
    node*temp2=temp1->next;
    void *dp;
    while(temp2->next!=NULL)
    {
      temp2=temp2->next;
      temp1=temp1->next;
    }
    temp1->next=NULL;
    dp=temp2->dp;
    l->count--;
    return dp;
}

bool lfull()
{
  node*temp=(node*)malloc(sizeof(node));
  if(temp)
  {
    return false;
  }
  return true;
}
void display(list*l)
{
	node*temp=l->head;
	while(temp!=NULL)
	{
		pf(temp->dp);
	    temp=temp->next;
	    	
	}
}
int main()
{
 int *x;
 list*l;
 l=creatll();
 if(!l)
 {
    printf("list creation failed\n");
    return 0;
 }
 printf("enter the number\n");
x=(int*)malloc(sizeof(int));
 while( scanf("%d",(int*)x)!=EOF)
 {
    if(add_first(l,x))
    {
		printf("succes\n");
	}
	x=(int*)malloc(sizeof(int));
	
 }
 display(l);
 printf("enter the key\n");
 	key=(int*)malloc(sizeof(int));

 scanf("%d",key);
 if(findingkey(l))
 {
  printf("%d is pracent \n",*key);
 }
 else{
  printf("%d not is pracent \n",*key);
 }
 printf("%d",*(int*)remove_first(l));
  printf("%d",*(int*)remove_last(l));

}
