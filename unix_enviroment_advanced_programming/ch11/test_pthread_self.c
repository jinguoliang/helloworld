#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void print_info(char *str)
{
	printf("%s : pid = %d, tid = %d\n",str,(int)getpid(),(int)pthread_self());
}

void* thread1_fun(void*arg)
{
	print_info("thread1");	
}

int main(void)
{
	char *errstr;
	pthread_t tid=0;
	int res=pthread_create(&tid,NULL,thread1_fun,NULL);
	sleep(5);
	print_info("main thread");
}

