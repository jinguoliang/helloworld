#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct s{
	int a;
	int b;
	int c;
};

void* thread1_func(void* arg)
{
//	struct s *ss;
//	ss=(struct s*)malloc(sizeof(struct s));
//	ss->a=1;
//	ss->b=2;
//	ss->c=3;
	struct s ss;
	ss.a=4;
	ss.b=5;
	ss.c=6;

	puts((char*)arg);
	return (void*)&ss;
}
void* thread2_func(void* arg)
{
	struct s *ss;
	ss=(struct s*)malloc(sizeof(struct s));
	ss->a=1;
	ss->b=2;
	ss->c=3;
//	struct s ss;
//	ss.a=4;
//	ss.b=5;
//	ss.c=6;

	puts((char*)arg);
	pthread_exit((void*)ss);
}

void main(void)
{
	int res;
	pthread_t tid1,tid2;
	void *ret;

	res=pthread_create(&tid1,NULL,thread1_func,"thread1:");
	if(res!=0)
		perror("pthread_create thread1 error");
	pthread_join(tid1,(void**)&ret);
	printf("%d\n",((struct s*)ret)->a);
	printf("%d\n",((struct s*)ret)->b);
	printf("%d\n",((struct s*)ret)->c);
	res=pthread_create(&tid2,NULL,thread2_func,"thread2:");
	if(res!=0)
		perror("pthread_create thread2 error");
	pthread_join(tid2,(void**)&ret);
	printf("%d\n",((struct s*)ret)->a);
	printf("%d\n",((struct s*)ret)->b);
	printf("%d\n",((struct s*)ret)->c);

}

