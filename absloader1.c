#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[10],label[10];
int w=0,addr,taddr,ptaddr,length=0,count=0,i=0,k=0,start,end,addres;
void check();
FILE*fp1,*fp2;
int main()
{
	fp1=fopen("input1.txt","r");
	fp2=fopen("output1.txt","w");
	printf("\t\t ABSLUTE LOADER\t\t\n");
	fprintf(fp2,"\n----------------------------------------------------------------\n");
	fprintf(fp2,"MEMORY ADRESS \t\t CONTAINTES\n\n");
	fprintf(fp2,"\n----------------------------------------------------------------\n");
	fscanf(fp1,"%s",input);
	while(strcmp(input,"E")!=0)
	{
		if(strcmp(input,"H")==0)
		{
			fscanf(fp1,"%s %x %x %s",label,&start,&end,input);
			addres=start;
		}
		else if(strcmp(input,"T")==0)
		{
			int l=length;
			fscanf(fp1,"%x %x %s",&taddr,&length,input);
			ptaddr=addr;
			addr=taddr;
			if(w==0)
			{
				ptaddr=start;
				w=1;
			}
			for(int k=0;k<(taddr-(ptaddr+l));k++)
			{ 
				addres+=1;
				fprintf(fp2,"xx");
				count++;
				if(count==4)
				{
					fprintf(fp2," ");
					i++;
					if(i==4)
					{
						fprintf(fp2,"\n\n%x\t\t",addres);
						i=0;
					}
					count=0;
				}
			}
			if(taddr==start)
			{
				fprintf(fp2,"\n\n%x\t\t",taddr);
			}
			fprintf(fp2,"%c%c",input[0],input[1]);
			check();
			fprintf(fp2,"%c%c",input[2],input[3]);
			check();
			fprintf(fp2,"%c%c",input[4],input[5]);
			check();
			fscanf(fp1,"%s",input);
		}
		else
		{
			fprintf(fp2,"%c%c",input[0],input[1]);
			check();
			fprintf(fp2,"%c%c",input[2],input[3]);
			check();
			fprintf(fp2,"%c%c",input[4],input[5]);
			check();
			fscanf(fp1,"%s",input);
		}
	}
		fprintf(fp2,"\n----------------------------------------------------------------\n");

	fclose(fp1);
	fclose(fp2);
    char ch2;
    fp2 = fopen("output1.txt", "r");
	ch2 = fgetc(fp2);
	while (ch2 != EOF)
	{
		printf("%c", ch2);
		ch2 = fgetc(fp2);
	}
	fclose(fp2);
	return 0;  
}
void check()
{
	addres+=1;
	taddr+=1;
	count++;
	if(count==4)
	{
	fprintf(fp2," ");
		i++;
		if(i==4)
		{
		  fprintf(fp2,"\n\n%x\t\t",taddr);
		  i=0;
		}
		count=0;	
	}
}
	



	
	
