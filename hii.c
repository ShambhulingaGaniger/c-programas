#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node
{
	void*dp;
	struct node *next;
}node;
typedef struct List
{
	node *head;
	int count;
}list;
list*creatlist()
{
	list*p=(list*)malloc(sizeof(list));
	if(p)
	{
		p->count=0;
		p->head=NULL;
		return p;
	} 
	return NULL;
}
bool insetion(list*p,node*pred,void*dp)
{
	node*newnode=(node*)malloc(sizeof(node));
	if(newnode)
	{
		newnode->dp=dp;
		if(p->count==0)
		{
			newnode->next=p->head->dp;
			p->head=newnode;
			p->count++;
		}
		else
		{
			newnode->next=pred->next;
			pred->next=newnode;
			p->count++;
		}
		return true;
	}
	return false;
}
void *deletion(list*p,node*pred)
{
	if(p->count==0)
	{
		return NULL;
	}
	node*temp;
	void*dp;
	if(pred==NULL)
	{
		temp=p->head;
		p->head=temp->next;
		dp=temp->dp;
		p->count--;
	}
	else
	{
		temp=pred->next;
		pred->next=temp->next;
		dp=temp->dp;
		p->count--;
	}
	return dp;
}
node*serchlist(list*p,void*dp,bool(*com)(void*,void*))
{
	if(p->count==0)
	{
		return NULL;
	}
	node*temp;
	temp=p->head;
	while(temp!=NULL)
	{
		if(com(temp->dp,dp))
		{
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}
void*retrive(list*p,void*dp,bool(*com)(void*,void*))
{
	node*temp=serchlist(p,dp,com);
	if(temp)
	{
		return temp->dp;
	}
	return NULL;
}
bool lisfull()
{
	node*temp=(node*)malloc(sizeof(node));
	if(temp)
	{
		return false;
	}
	return true;
}
bool lisempty(list*p)
{
	
	if(!p->count==0)
	{
		return false;
	}
	return true;
}
int listcount(list*p)
{
	return p->count;
}
void listdisplay(list*p,void(*pf)(void*))
{
	node*temp=p->head;
	while(temp!=NULL)
	{
		pf(temp->dp);
		temp=temp->next;
	}
}
bool listdestroy(list*p)
{
	if(p)
	{
	node*temp=p->head,*dlt;
	void*dp;
	while(temp!=NULL)
	{
		dlt=temp;
		temp=temp->next;	 
		dp=dlt->dp;
		free(dp);
		free(dlt);
	}
	free(p);
	return true;
  }
  return false;
}
		
		
			
			

