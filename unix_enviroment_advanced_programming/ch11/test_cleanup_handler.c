#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void cleanup(void *args)
{
	printf("cleanup: %s\n",(char*)args);
}

void* thread1_fun(void* args)
{
	puts("in thread1");
	pthread_cleanup_push(cleanup,"thread1 first");
	pthread_cleanup_push(cleanup,"thread1 second");

	return 0;
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
}

void* thread2_fun(void* args)
{
	puts("in thread2");
	pthread_cleanup_push(cleanup,"thread2 first");
	pthread_cleanup_push(cleanup,"thread2 second");

	pthread_exit(0);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
}

void main(void)
{
	pthread_t tid;
	pthread_create(&tid,NULL,thread1_fun,NULL);
	pthread_join(tid,NULL);
	pthread_create(&tid,NULL,thread2_fun,NULL);
	pthread_join(tid,NULL);
	
}
