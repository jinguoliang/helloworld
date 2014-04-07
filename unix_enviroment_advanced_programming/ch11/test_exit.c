/*
*filename:	test_exit.c
*author: 	Jinux
*create:	2014年02月23日 星期日 20时58分45秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ourhdr.h"

struct foo{
	int a, b, c;
};


void printfoo(const char *s,const struct foo *fp){
	printf(s);
	printf(" structure at 0x%x\n",(unsigned)fp);
	printf(" foo.a = %d\n",fp->a);
	printf(" foo.b = %d\n",fp->b);
	printf(" foo.c = %d\n",fp->c);
}

void *thr_fn1(void *arg)
{
	struct foo *foo=(struct foo*)malloc(sizeof(struct foo));
	foo->a=1;
	foo->b=2;
	foo->c=3;

	printfoo("thread 1:\n",foo);
	pthread_exit((void*)foo);
}


void *thr_fn2(void *arg)
{
	printfoo("thread 2:\n",(struct foo*)arg);
	pthread_exit((void*)0);
}

int main(int argc,char *argv[])
{
	int err;
	pthread_t tid1,tid2;
	struct foo *fp;

	err=pthread_create(&tid1,NULL,thr_fn1,NULL);
	if(err!=0)
		err_quit("can't create thread 1:%s\n",strerror(err));
	err=pthread_join(tid1,(void*)&fp);
	if(err!=0)
		err_quit("join error thread 1:%s\n",strerror(err));
	printfoo("mail thread:\n",fp);
	err=pthread_create(&tid2,NULL,thr_fn2,fp);
	if(err!=0)
		err_quit("can't create thread 2:%s\n",strerror(err));
	err=pthread_join(tid1,(void*)&fp);
	if(err!=0)
		err_quit("join error thread 2:%s\n",strerror(err));
	

	return 0;
}

