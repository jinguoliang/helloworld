/*
*filename:	test_parent_die.c
*author: 	Jinux
*create:	Mon 03 Feb 2014 11:22:20 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "ourhdr.h"


static void sig_hup(int signo)
{
	printf("SIGHUP received, pid=%d\n",getpid());
}

static void pr_ids(char *name)
{
	printf("%s: pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n",
			name,getpid(),getppid(),getpgrp(),tcgetpgrp(STDIN_FILENO));
	fflush(stdout);
}

int main(int argc,char *argv[])
{
	char c;
	pid_t pid;

	pr_ids("parent");
	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0){
		sleep(5);
		exit(0);
	}else{
		pr_ids("child");
		signal(SIGHUP,sig_hup);
		kill(getpid(),SIGTSTP);
		pr_ids("child");
		if(read(STDIN_FILENO,&c,1)!=1)
			printf("read error from controlling TTY,errno = %d\n",errno);
	
		exit(0);
	}



	return 0;
}

