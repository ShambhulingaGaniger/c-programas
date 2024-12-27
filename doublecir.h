#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct dnode
{
	void*dp;
	struct dnode *next,*prev;
}dnode;
typedef struct dd
{
	dnode*head;
	int count;
}dll;
dll*creatdlistd()
{
	dll*p;
	p=(dll*)malloc(sizeof(dll));
	if(p)
	{
		p->head=NULL;
		p->count=0;
		return p;
	}
	return NULL;
}
bool inseriondd(dll*p,dnode*prev,void*dp)
{
	dnode*newnode=(dnode*)malloc(sizeof(dnode));
	if(newnode)
	{
		newnode->dp=dp;
		if(!p->head)
			{
				newnode->next=p->head;
			    newnode->prev=NULL;
			    p->head=newnode;
			}
			
		else if(prev==NULL)
		{
			if(!p->head)
			{
				newnode->next=p->head;
			    newnode->prev=NULL;
			    p->head=newnode;
			}
			else
			{
			newnode->next=p->head;
			newnode->prev=NULL;
			p->head->prev=newnode;
			p->head=newnode;
		   }
		}

		else
		{
			newnode->next=prev->next;
			newnode->prev=prev;
			prev->next=newnode;
			newnode->next->prev=newnode;
		}
		p->count++;
		return true;
	}
	return false;
}
void* deletiondd(dll*p,dnode*prev)
{
	dnode*temp;
	void*dout;
	if(p->count==0)
	{
		return NULL;
	}
	if(!prev)
	{
		temp=p->head;
		p->head=temp->next;
		p->head->prev=temp->next;
	}
	else if(!prev->next)
	{
		temp=prev;
		temp->prev->next=temp->next;
	}
	else
	{
		temp=prev->next;
		prev->next=temp->next;
		temp->next->prev=prev;
	}
	dout=temp->dp;
	free(temp);
	p->count--;
	return dout;
}
void dlldisplay(dll *p,void (*pf)(void*))
{
	dnode*temp=p->head;
	while(temp)
	{
		pf(temp->dp);
		temp=temp->next;

}
}
void rev(dll*p,void (*pf)(void*))
{
	dnode*temp=p->head;
	while(temp->next)
	  temp=temp->next;
	while(temp)
	  {
		pf(temp->dp);
		temp=temp->prev;
	 }
}
		


			
			
			
			

