/*
*filename:	test_condition.c
*author: 	Jinux
*create:	2014年02月23日 星期日 20时39分08秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct msg{
	struct msg *m_next;
};

struct msg *workq;
pthread_cond_t qready=PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock=PTHREAD_MUTEX_INITIALIZER;

void process_msg(void)
{
	struct msg *mp;

	for(;;){
		pthread_mutex_lock(&qlock);
		while(workq==NULL)
			pthread_cond_wait(&qready,&qlock);
		mp=workq;
		workq=mp->m_next;
		pthread_mutex_unlock(&qlock);
		//process the message
	}
}

void enqueue_msg(struct msg *mp)
{
	pthread_mutex_lock(&qlock);
	mp->m_next=workq;
	workq=mp;
	pthread_mutex_unlock(&qlock);
	pthread_cond_signal(&qready);
}

int main(int argc,char *argv[])
{

	return 0;
}

