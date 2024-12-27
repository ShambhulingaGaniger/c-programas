#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct arr
{
	void**st;
	int head,count,size;
	bool(*com)(void*,void*);
	void(*pf)(void*);
}alist;
alist*creatlist(bool(*com)(void*,void*),void(*pf)(void*))
{
	alist*p=(alist*)malloc(sizeof(alist));
	if(p)
	{
		printf("enter the size of the list\n");
		scanf("%d",&p->size);
		p->st=(void**)calloc(p->size,sizeof(void*));
		if(p->st)
		{
			p->head=-1;
			p->count=0;
			p->com=com;
			p->pf=pf;
			return p;
		}
		free(p);
	}
	return NULL;
}
bool inserte(void*dp,alist*p,int prev)
{
	if(p->count==p->size)
	{
		return false;
	}
	printf("%d %d",p->count,p->size);
	if(prev==p->head)
	{
		p->head++;
		p->st[p->head]=dp;
	}
	else
	{
		int i;
		for( i=p->head;i>=prev;i--)
		{
			p->st[i+1]=p->st[i];
		}
		p->st[i+1]=dp;
		p->head++;
	}
	p->count++;
	return true;
}
bool listempty(alist*p)
{
	if(p->count==0)
	{
		return true;
	}
	return false;
}
bool listfull(alist*p)
{
	if(p->count==p->size)
	{
		return true;
	}
	return false;
}
void disply(alist*p)
{
	for(int i=p->head;i>=0;i--)
	{
		p->pf(p->st[i]);
	}
} 
int serchlist(alist*p,void*dp)
{
	for(int i=p->head;i>=0;i--)
	{
		if(p->com(p->st[i],dp))
		{
			return i;
		}
	}
	return -1;
}
void*deletion(alist*p,int prev)
{
	if(p->count==0)
	{
		return NULL;
	}
	void*dp;
	if(prev==p->head)
	{
		dp=p->st[p->head];
		p->head--;
	}
	else
	{
	    dp=p->st[p->head];
		for(int i=p->head;i>=prev;i--)
		{
			p->st[i]=p->st[i+1];
		}
		p->head--;
	}
	p->count--;
	return dp;
}

	
	 
