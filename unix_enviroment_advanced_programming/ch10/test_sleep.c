#include "ourhdr.h"
#include <signal.h>
#include <unistd.h>
#include <setjmp.h>

static jmp_buf env_alrm;

static void sig_alrm1(int signo)
{

}

static void sig_alrm2(int signo)
{
	longjmp(env_alrm,1);
	
}


unsigned int sleep1(unsigned int nsecs)
{
	if(signal(SIGALRM,sig_alrm1)==SIG_ERR)
		return nsecs;
	
	alarm(nsecs);
	pause();
	return nsecs;

}

unsigned int sleep2(unsigned int nsecs)
{
	if(signal(SIGALRM,sig_alrm2)==SIG_ERR)
		return nsecs;

	if(setjmp(&env_alrm)==0){
		alarm(nsecs);
		pause();
	}
	return nsecs;
}

int main(void)
{
	sleep2(5);

}
