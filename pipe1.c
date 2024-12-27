
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fd1[2],fd2[2],n,s,result;
long int buffer[100];
pipe(fd1);
pipe(fd2);
if(fork())
{
close(fd1[0]);
printf("enter number to find factorial\n");
scanf("%d",&n);
write(fd1[1],buffer,n);
close(fd1[1]);
sleep(1);
close(fd1[2]);
result=read(fd2[0],buffer,100*sizeof(buffer));
printf("factorial of the number is %d\n",result);
}
else
{
sleep(2);
s=read(fd1[0],buffer,100*sizeof(buffer));
printf("hello world this is child process\n");
int i,f=1;
for(i=s;i>0;i--)
{
f=f*i;
}
close(fd2[0]);
write(fd2[1],buffer,f);
}
return 0;
}
