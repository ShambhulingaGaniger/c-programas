#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<semaphore.h>
#include<math.h>
#include<unistd.h>
#include<sys/sem.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/shm.h>
#define KEY 1011
int main()
{
	sem_t*mutex;
	key_t key=KEY;
	int shmid,pid;
	shmid=shmget(key,sizeof(sem_t),IPC_CREAT|0666);
	sem_init(mutex,1,0);
	pid=fork();
	if(pid>0)
	{
		sleep(3);
		printf("parent -hi");
		sem_post(mutex);
		printf("p, i am going to terminate\n");
		exit();
	}
	else if(pid==0)
	{
		printf(" i am child going to wait \n");
		sem_wait(mutex);
		printf(" hi good morning \n");
		printf(" i AM child going to exit \n");
		exit();
	}
	return 0;
}



