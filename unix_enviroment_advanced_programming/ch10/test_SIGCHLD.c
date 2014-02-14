#include "ourhdr.h"
#include <sys/wait.h>

static  void  sig_cld(int );

int main(void)
{
	pid_t pid;

	if(signal(SIGCHLD,sig_cld)==SIG_ERR)
		err_sys("signal error");

	puts("start");

	if((pid=fork())<0){
		err_sys("fork error");
	}else if(pid==0){
		puts("child");
		sleep(1);
		_exit(0);
	}

	puts("parent");
	pause();
	return 0;

}

static void sig_cld(int signo)
{

	pid_t pid;
	int status;

	printf("SIGCHLD received\n");

	if((pid=wait(&status))<0)
		perror("wait error");

	printf("pid=%d\n",pid);
}
