#include"ListAdt.h"
#include<string.h>
typedef struct stude
{
	char stud[30];
	int sub1,sub2,sub3;
}stu;
void printdata(void*dp)
{
	list*k=(list*)dp;
	node*temp=k->head;
	while(temp!=NULL)
	{
		stu*student=(stu*)temp->dp;
		 printf("Student Name: %s\n", student->stud);
        printf("Subject 1 Marks: %d\n", student->sub1);
        printf("Subject 2 Marks: %d\n", student->sub2);
        printf("Subject 3 Marks: %d\n", student->sub3);
        temp = temp->next;
	}
}
int main()
{
	list*op;
	stu*k;
	int ch;
	op=creatlist();
	if(!op)
	{ 
		printf("list creation failedd\n");
		return 0;
	}
	while(1)
	{
		printf("enter the choice \n 1)enter the data\n2)exite\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			list*ip=creatlist();
			k=(stu*)malloc(sizeof(stu));
			printf("ente the student name\n");
			scanf("%s",k->stud);
			printf("ente the subject 1 marks\n");
			scanf("%d",&k->sub1);
			printf("ente the subject 2 marks\n");
			scanf("%d",&k->sub2);
			printf("ente the subject 3 marks\n");
			scanf("%d",&k->sub3);
			insetion(ip,NULL,k);
			insetion(op,NULL,ip);
		}
		else
		 break;
	}
	if(listempty(op))
	{
		printf("list is empty\n");
		return 0;
	}
	else
	{
		listdisplay(op,printdata);
	}
	return 0;
}

	

	
