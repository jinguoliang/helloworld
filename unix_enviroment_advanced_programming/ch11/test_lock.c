/*
*filename:	test_lock.c
*author: 	Jinux
*create:	2014年02月22日 星期六 22时56分36秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct foo{
	int		f_count;
	pthread_mutex_t	f_lock;
};

struct foo* foo_alloc(void)
{
	struct foo  *fp;

	if((fp=malloc(sizeof(struct foo)))!=NULL){
		fp->f_count=1;
		if(pthread_mutex_init(&fp->lock,NULL)!=0){
			free(fp);
			return NULL;
		}
	}

	return NULL;
}

void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_count);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_count);
}

void foo_rele(struct foo *fp)
{
	pthread_mutex_lock(&fp->f_lock);
	if(--fp->f_count==0){
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	}else{
		pthread_mutex_unlock(&fp->f_lock);
	}
}


int main(int argc,char *argv[])
{
	
	

	return 0;
}

