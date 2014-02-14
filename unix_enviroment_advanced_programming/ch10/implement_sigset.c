#include <signal.h>
#include <errno.h>

#define SIGBAD_j(signo) ((signo)<=0||(signo)>NSIG)
#define sigemptyset_j(sigset) ((*sigset)=0)
#define sigfillset_j(sigset) ((*sigset)=~(sigset_t)0,0)

int sigaddset_j(sigset_t *set,int signo)
{
	if(SIGBAD_j(signo)) {errno=EINVAL;return -1;}

	*set |= (sigset_t)(1<<(signo-1));
	return 0;
}

int sigdelset_j(sigset_t *set,int signo)
{
	if(SIGBAD_j(signo)) {errno=EINVAL;return -1;}

	*set &= ~(1<<(signo-1));
	return 0;
}

int sigismember_j(const sigset_t *set,int signo)
{
	if(SIGBAD_j(signo)) {errno=EINVAL;return -1;}
	return *set&(1<<(signo-1));
}
