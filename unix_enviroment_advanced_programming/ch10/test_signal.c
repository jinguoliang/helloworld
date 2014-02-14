/*
*filename:	test_signal.c
*author: 	Jinux
*create:	Wed 05 Feb 2014 10:49:59 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/


#include "ourhdr.h"
#include <signal.h>

static void sig_usr(int);

int main(int argc,char *argv[])
{
	if(signal(SIGUSR1,sig_usr)==SIG_ERR)
		err_sys("can't catch SIGUSR1");
	if(signal(SIGUSR2,sig_usr)==SIG_ERR)
		err_sys("can't catch SIGUSR1");

//	for(;;)
//		pause();

	sleep(100);
	puts("finish");
	return 0;
}

static void sig_usr(int signo)
{
	if(signo==SIGUSR1)
		puts("received SIGUSR1");
	else if(signo==SIGUSR2)
		puts("received SIGUSR2");
	else 
		err_quit("received signal %d\n",signo);
}
