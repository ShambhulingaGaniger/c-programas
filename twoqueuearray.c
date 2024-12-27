#include<stdio.h>
typedef struct arr
{
	int r,f,count;
}q;
int qmax[50],max;
q q1,q2;
void creat1q()
{
	printf("enter the size of the array\n");
	scanf("%d",&max);
	q1.count=0;
	q1.r=-1;
	q1.f=-1;
}
void creat2q()
{
	q2.count=0;
	q2.r=max-1;
	q2.f=max-1;
}
int insertion_first(int i)
{
	if((q1.f+1)==q2.r)
	{
		return 0;
	}
	else
	{
		q1.r++;
		qmax[q1.r]=i;
		q1.count++;
		if(q1.f==-1)
		{
			q1.f=0;
		}
	}

}
int insertion_las(int i)
{
	if((q1.f+1)==q2.r)
	{
		return 0;
	}
	else
	{
		q2.r--;
		qmax[q1.r]=i;
		q2.count++;
		if(q2.f==max)
		{
			q2.f=max-1;
		}
	}

}
int delete_first()
{
	int i;
   if(q1.count==0)
   {
	 return 0;
   }	
 if(q1.count==1)
   {
      q1.r=-1;
	  q1.f=-1;
   }
   i=qmax[q1.f];
   q1.f++;
   q1.count--;
   return i;
}
int delete_last()
{
	int i;
   if(q2.count==0)
   {
	 return 0;
   }	
 if(q2.count==1)
   {
      q2.r=-1;
   }
   i=qmax[q2.f];
   q2.f--;
   q2.count--;
   return i;
}
int qfull()
{
	if(q1.r+1==q2.r)
	{
		return 1;
	}
	return 0;
}
void display1q()
{
	if(q1.count==0)
	{
		printf("queue is empty\n");
		return;
	}
	int i=0;
	for(i=q1.f;i<=q1.r;i++)
	{
		printf("%d",qmax[i]);
	}
}
void display2q()
{
	if(q2.count==0)
	{
		printf("queue is empty\n");
		return;
	}
	int i=0;
	for(i=q2.f;i>=q2.r;i--)
	{
		printf("%d",qmax[i]);
	}
}
int main()
{
  int x,y;
  creat1q();
  creat2q();
  	while(1)
	{
		printf("\nenter the choice \n1)insert1\n2)insert3\ndelet1\n4)delet2\n5)display1\n6)display2\n7)exit\n");
		scanf("%d",&y);
		switch (y)
		{
         case 1:printf("ente the num\n");
		         scanf("%d",&x);
				 insertion_first(x);
				 break;
		case 2:printf("ente the num\n");
		         scanf("%d",&x);
				 insertion_las(x);
				 break;
		case 3:x=delete_first();
		       printf("delete 1 eliment %d\n",x);
			   break;
		case 4:x=delete_last();
		       printf("delete eliment %d\n",x);
			   break;
		case 5:display1q();
		       break;
		case 6:display2q();
		       break;
		case 7:return 0;
		default:printf("invalid choice\n");
		}
	}
	return 0;
		
	}

