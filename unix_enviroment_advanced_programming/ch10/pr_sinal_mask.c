#include "ourhdr.h"
#include <errno.h>
#include <signal.h>

void pr_sigset(sigset_t *sigset)
{
		puts("");
		if(sigismember(sigset, SIGINT)) printf("SIGINT  ");
		if(sigismember(sigset, SIGQUIT)) printf("SIGQUIT  ");
		if(sigismember(sigset, SIGUSR1)) printf("SIGUSR1  ");
		if(sigismember(sigset, SIGALRM)) printf("SIGALRM  ");
		puts("");
}

void pr_mask(const char *str)
{
	sigset_t sigset;
	int errno_saved;

	errno_saved=errno;

	if(sigprocmask(0,NULL,&sigset)<0)
		err_sys("sigprocmask error");

	printf("%s",str);
	pr_sigset(&sigset);
}


/*
main(void)
{
	sigset_t sigset,oset;

	if(sigemptyset(&sigset)<0)
		err_sys("sigemptyset errror");
	if(sigaddset(&sigset,SIGINT)<0)
		err_sys("sigaddset errror");


	pr_mask("first mask");
	if(sigprocmask(SIG_BLOCK,&sigset,&oset)<0)
		err_sys("sigprocmask error");

	if(sigismember(&oset, SIGINT)) 
		printf("SIGINT  \n");
	else
		printf("no SIGINT\n");
	
	pr_mask("second mask");
}


*/
