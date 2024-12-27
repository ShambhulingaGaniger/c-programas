#include"ListAdt.h"
#include<stdlib.h>
#include<string.h>
typedef struct course
{
	char code[10],name[20],ch;
	int l,p,t,cie,see;
}cou;
bool com(void*dp,void*pq)
{
	cou*c=(cou*)dp;
	cou*d=(cou*)pq;
	if(!strcmp(d->code,c->code))
	{
	     return true;
	     }
	return false;
}
 void printdata(void*dp)
 {
	 cou *a=(cou*)dp;
	 printf("course code %s\n",a->code);
	 printf("course name %s\n",a->name);
	 printf("course L:P:T %d:%d:%d\n",a->l,a->p,a->t);
	 printf("course code %d\n",a->cie);
	 printf("course SEE %d\n",a->see);
}

	 
 int main()
 {
	 int ch;
	 node*prev;
	 char pkey[20];
	 list*p;
	 bool res;
	 cou*c;
	 
	 p=creatlist();
	 if(!p)
	 {
		 printf("list  is not \n");
		 return 0;
	 }
	 while(1)
	 {
		 printf("\n enten choice\n1)insertion\n2)delition\n3)retrive\n4)display\n5)list empty\n6)listfull\n7)serch\n8)exit");
		 scanf("%d",&ch);
		 switch(ch)
		 {
			 case 1:c=(cou*)malloc(sizeof(cou));
			        printf("enter the choice\n1)big\n2)mid\n3)last\n");
			         scanf("%d",&ch);
			         switch(ch)
			         {
						 case 1:prev=NULL;
						        break;
						 case 2:printf("ener the prevase course code to\n");
						        scanf("%s",pkey);
						        prev=serchlist(p,pkey,com);
						        if(!prev)
									printf("serch failed \n");
								break;
						 case 3:prev=p->head;         
						        while(prev->next!=NULL)
						            prev=prev->next;
						        break;
						 default:printf("invalid choice\n");
						         break;
					 }
					 if(ch==2&&prev==NULL)
					    break;
					 if(!c){
					    printf("list is full\n");
					 break;}
					 printf("enter the code\n");
					 scanf("%s",c->code);
					 printf("enter the name\n");
					 scanf("%s",c->name);
					 printf("enter the L:P:T\n");
					 scanf("%d%d%d",&c->l,&c->p,&c->t);
					 printf("enter the CIE\n");
					 scanf("%d",&c->cie);
					 printf("enter the code\n");
					 scanf("%d",&c->see);
					 res=insetion(p,prev,c);
					 res==true?printf("succes\n"):printf("not succes\n");
					 break;
				case 2:printf("enter choice\n1)delete first\n2)delete mid\n3)delete last\n");
				       scanf("%d",&ch);
				       switch(ch)
				       {
						   case 1:prev=NULL;
						        break;
						   case 2:printf("ener the prevase course code to\n");
						        scanf("%s",pkey);
						        node*t=p->head;
						        prev=NULL;
						        while(t!=NULL&&strcmp(pkey,((cou*)(t->dp))->code))
						        {
									prev=t;
									t=t->next;
									
								}
						        prev=serchlist(p,pkey,com);
						        if(!prev)
									printf("serch failed \n");
								break;
						  case 3:prev=NULL;
						         node*temp=p->head;         
						        while(temp->next!=NULL){
									prev=temp;
						            temp=temp->next;
								}
						        break;
						 default:printf("invalid choice\n");
						         break;
							 }
							 c=(cou*)deletion(p,prev);
							    if(c){
							       printdata(c);
							       free(c);
						          }
						          else
						          {
									  printf("list is empty\n");
								  }
								  break;
						case 3:printf("enter the pkey to retrive\n");
						       scanf("%s",pkey);
						       c=(cou*)retrive(p,pkey,com);
						       printdata(c);
						       break;
						case 4:if(!listempty(p))
						       {
						       printf("printing the content of the list\n");
						       listdisplay(p,printdata);
						      }else
						      {
								  printf("list is empty\n");
							  }
							  break;
					   case 5:if(listempty(p))
					          {
								  printf("list is empty \n");
							  }
							  else
							  {
								  printf("list is empty \n");
							  }
							  break;
					   default:printf("in valid coice \n");
				   }
			   }
			   return 0;
		   }
						       
						       
						
							 
						        
					 
					 
						 
						 
								
								
			           
			  
