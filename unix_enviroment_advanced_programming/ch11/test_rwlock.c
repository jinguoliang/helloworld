/*
 *filename:	test_rwlock.c
*author: 	Jinux
*create:	2014年02月23日 星期日 18时31分13秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdlib.h>
#include <pthread.h>
#include "ourhdr.h"
#include <math.h>

struct job{
	struct job *j_next;
	struct job *j_prev;
	pthread_t	j_tid;
	int 		j_id;
};

struct queue{
	struct job		*q_head;
	struct job		*q_tail;
	pthread_rwlock_t q_lock;
};


int queue_init(struct queue *qp)
{
	int err;

	qp->q_head=NULL;
	qp->q_tail=NULL;
	err=pthread_rwlock_init(&qp->q_lock,NULL);
	if(err!=0)
		return(err);

	//other initialization
	return(0);
}

void job_insert(struct queue *qp,struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next=qp->q_head;
	jp->j_prev=NULL;
	if(qp->q_head!=NULL)
		qp->q_head->j_prev=jp;
	else
		qp->q_tail=jp;
	qp->q_head=jp;
	pthread_rwlock_unlock(&qp->q_lock);
}

void job_append(struct queue *qp,struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	jp->j_next=NULL;
	jp->j_prev=qp->q_tail;
	if(qp->q_tail!=NULL)
		qp->q_tail->j_next=jp;
	else
		qp->q_head=jp;
	qp->q_tail=jp;
	pthread_rwlock_unlock(&qp->q_lock);
}

void job_remove(struct queue *qp,struct job *jp)
{
	pthread_rwlock_wrlock(&qp->q_lock);
	if(jp==qp->q_head){
		qp->q_head=jp->j_next;
		if(qp->q_tail==jp)
			qp->q_tail=NULL;
	}else if(jp==qp->q_tail){
		qp->q_tail=jp->j_prev;
		if(qp->q_head==jp)
			qp->q_head=NULL;
	}else{
		jp->j_prev->j_next=jp->j_next;
		jp->j_next->j_prev=jp->j_prev;
	}
	pthread_rwlock_unlock(&qp->q_lock);
}

struct job *job_find(struct queue *qp,pthread_t id)
{
	struct job *jp;

	if(pthread_rwlock_rdlock(&qp->q_lock)!=0)
		return(NULL);

	for(jp=qp->q_head;jp!=NULL;jp=jp->j_next)
		if(pthread_equal(jp->j_tid,id))
			break;

	pthread_rwlock_unlock(&qp->q_lock);
	return(jp);
}


struct queue head;

//child thread get the job and process.
void *child_fun(void*arg)
{
	struct job *jp;
	printf("thread %d start\n",(int)arg);

	while(1){
		jp=job_find(&head,pthread_self());
		if(jp!=NULL){
			printf("thread%d %d process job%d\n",(int)arg,jp->j_tid,jp->j_id);
			job_remove(&head,jp);
		}
		else
			sleep((long)random%2);
	}
}


int main(int argc,char *argv[])
{
	int tid_count=3,i;
	pthread_t tids[tid_count];
	struct job *job;

	//create jobs;
	queue_init(&head);

	//create child;
	for(i=0;i<tid_count;i++)
		pthread_create(&tids[i],NULL,child_fun,(void*)i);
	
	//main thread insert the jobs;
	for(i=0;;i++){
		job=(struct job*)malloc(sizeof(struct job));
		job->j_tid=tids[(long)i%tid_count];
		job->j_id=i;
		job_append(&head,job);
		sleep(1);
	}

	return 0;
}

