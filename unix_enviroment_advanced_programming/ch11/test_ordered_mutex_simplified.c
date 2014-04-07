/*
*filename:	test_ordered_mutex_simplified.c
*author: 	Jinux
*create:	2014年02月23日 星期日 00时07分02秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NHASH	29
#define HASH(fp)	(((unsigned long)fp)%NHASH)

struct foo *fh[NHASH];
pthread_mutex_t hashlock = PTHREAD_MUTEX_INITIALIZER;

struct foo{
	int				f_count;
	pthread_mutex_t f_lock;
	struct foo		*f_next;
	int				f_id;
}

struct foo *foo_alloc(void)
{
	struct foo		*fp;
	int				idx;

	if((fp=malloc(sizeof(struct foo)))!=NULL){
		fp->f_count=1;
		if(pthread_mutex_init(&fp->f_lock)!=0){
			free(fp);
			return(NULL);
		}
		idx=HASH(fp);
		pthread_mutex_lock(&hashlock);
		fp->f_next=fh[idx];
		fh[idx]=fp;
		pthread_mutex_lock(&fp->f_lock);
		pthread_mutex_unlock(&hashlock);

	}
	return(fp);
}

void foo_hold(struct foo *fp)
{
	pthread_mutex_lock(&hashlock);
	fp->f_count++;
	pthread_mutex_unlock(&hashlock);
}

struct foo	*foo_find(int id)
{
	struct foo	*fp;
	int 		idx;

	idx=HASH(fp);
	pthread_mutex_lock(&hashlock);
	for(fp=fh[idx];fp!=NULL;fp=fp->f_next){
		if(fp->f_id == id){
			fp->f_count++;
			break;
		}
	}
	pthread_mutex_unlock(&hashlock);
	return(fp);
}

void foo_rele(struct foo *fp)
{
	struct foo *tfp;
	int 		idx;

	pthread_mutex_lock(&hashlock);
	if(--fp->f_count==0){
		idx=HASH(fp);
		tfp=fh[idx];
		if(tfp==fp){
			fh[idx]=fp->f_next;
		}else{
			while(tfp->f_next!=fp){
				tfp=tfp->f_next;
			}
			tfp->f_next=fp->f_count;
		}
		pthread_mutex_unlock(&hashlock);
		pthread_mutex_destroy(&fp->f_lock);
		free(fp);
	}else{
		pthread_mutex_unlock(&hashlock);
	}
}
int main(int argc,char *argv[])
{

	return 0;
}

