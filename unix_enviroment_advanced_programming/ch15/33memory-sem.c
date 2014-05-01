/*
*filename:	33memory-mapped.c
*author: 	Jinux
*create:	2014年04月28日 星期一 22时54分58秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define NLOOPS 1

#define SIZE sizeof(long)

static int
update(long *ptr)
{
	return ((*ptr)++);
}

int main(int argc,char *argv[])
{
	int shmid,i,counter;
	pid_t pid;
	void *area;
	struct shmid_ds buf;

	if((shmid=shmget(IPC_PRIVATE,SIZE,IPC_CREAT))<0)
		err_sys("shmget error");

	if((area=shmat(shmid,NULL,0))<0)
		err_sys("shmat error");

	if(memset(area,0,SIZE)<0)
		err_sys("memset error");

	shmctl(shmid,IPC_STAT,&buf);
	printf("thread attached = %d\n",buf.shm_nattch);
//	long *nump=((long*)area);
//	*nump=0;

	printf("the area = %ld\n",*(long*)area);

//	TELL_WAIT();

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0){
		for(i=0;i<NLOOPS;i+=2){
			if((counter = update((long*)area))!=i)
				err_quit("parent: expected %d, got %d",i,counter);
			printf("parent: counter = %d\n",counter);

			TELL_CHILD(pid);
			WAIT_CHILD();
		}
	}else{
		for(i=1;i<NLOOPS+1;i+=2){
			WAIT_PARENT();

			if((counter=update((long*)area))!=i)
				err_quit("child: expected %d, got %d",i,counter);

			printf("child: counter = %d\n",counter);
			
			TELL_PARENT(getppid());
		}

	}

	return 0;
}

