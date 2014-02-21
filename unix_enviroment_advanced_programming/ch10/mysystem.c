/*
*filename:	mysystem.c
*author: 	Jinux
*create:	2014年02月16日 星期日 22时44分14秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>


void myhandler(int signo)
{
	if(signo==SIGQUIT)
		printf("SIGQUIT:\t%d\n",getpid());
	else
		printf("SIGINT:\t%d\n",getpid());
}

int system_j(const char *cmdstring)
{

	pid_t 				pid;
	int 				status;
	struct sigaction	ignore,saveintr,savequit;
	sigset_t			chldmask,savemask;

	if(cmdstring==NULL)
		return 1;

	ignore.sa_handler=myhandler;
	sigemptyset(&ignore.sa_mask);
	ignore.sa_flags=0;
	if(sigaction(SIGINT,&ignore,&saveintr)<0)
		return -1;
	if(sigaction(SIGQUIT,&ignore,&savequit)<0)
		return -1;
	sigemptyset(&chldmask);
	sigaddset(&chldmask,SIGCHLD);
	if(sigprocmask(SIG_BLOCK,&chldmask,&savemask)<0)
		return -1;

	if((pid=fork())<0)
		status=-1;
	else if(pid==0){
//		sigaction(SIGINT,&saveintr,NULL);
//		sigaction(SIGQUIT,&saveintr,NULL);
		sigprocmask(SIG_SETMASK,&savemask,NULL);

		execl("/bin/sh","sh","-c",cmdstring,(char*)0);
		_exit(127);
	}else{
		while(waitpid(pid,&status,0)<0)
			if(errno!=EINTR){
				status=-1;
				break;
			}
	}
	sigaction(SIGINT,&saveintr,NULL);
	sigaction(SIGQUIT,&saveintr,NULL);
	sigprocmask(SIG_SETMASK,&savemask,NULL);

	return status;
}


int main(int argc,char *argv[])
{
	if(system("ed")==-1)    ///ignored the SIGINT but not SIGQUIT.
		perror("system error");

	return 0;
}

