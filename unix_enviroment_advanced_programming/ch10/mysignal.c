#include "ourhdr.h"
#include <signal.h>

typedef void Sigfunc(int );

Sigfunc* mysignal(int signo,Sigfunc *func)
{
	struct sigaction act,oact;
	
	act.sa_handler=func;
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	if(signo==SIGALRM){
#ifdef SA_INTERRUPT
		act.sa_flags|=SA_INTERRUPT;
#endif
	}else{
#ifdef SA_RESTART
		act.sa_flags|=SA_RESTART;
#endif
	}


	if(sigaction(signo,&act,&oact)<0)
		return SIG_ERR;
	return (oact.sa_handler);
}

void func(int signo)
{
	puts("catch it");
}

void main(void)
{
	if(mysignal(SIGQUIT,func)==SIG_ERR)
		err_sys("signal error");
	sleep(10);
}
