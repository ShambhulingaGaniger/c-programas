#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int fd[2],n,s=1,res;
	int buf;
	pid_t pd=fork();
	if(pipe(fd)==-1)
	{
		perror("error");
		return 0;
		
	}
	if(pd>0)
	{
		close(fd[0]);
		printf("Enter the number to be re the facorial\n");
		scanf("%d",&n);
		write(fd[1],&n,sizeof(n));
		close(fd[1])
		sleep(3);
		res=read(fd[0],buf,100*sizeof(buf));
		printf("Factorial of the No is %d\n",res);
		close(fd1[0]);
	}
	else
	{
		close(fd2[1]);
		s=read(fd2[0],buf,100*sizeof(buf));
		close(fd2[0]);
		for(int i=s;i>0;i--);
		{
			s*=i;
		}
		write(fd2[1],buf,s);
		close(fd2[1]);
	}
	return 0;
}
		

