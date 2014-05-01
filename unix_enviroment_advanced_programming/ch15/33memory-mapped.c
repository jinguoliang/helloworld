/*
*filename:	33memory-mapped.c
*author: 	Jinux
*create:	2014年04月28日 星期一 22时54分58秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <fcntl.h>
#include <sys/mman.h>

#define NLOOPS 1000

#define SIZE sizeof(long)

static int
update(long *ptr)
{
	return ((*ptr)++);
}

int main(int argc,char *argv[])
{
	int fd,i,counter;
	pid_t pid;
	void *area;

	if((fd=open("/dev/zero",O_RDWR))<0)
		err_sys("open error");
	if((area=mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0))==MAP_FAILED)
		err_sys("mmap error");
	close(fd);

	TELL_WAIT();

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

