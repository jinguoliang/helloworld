/*
*filename:	call_noreentrant_in_sighandler.c
*author: 	Jinux
*create:	Thu 06 Feb 2014 09:33:01 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <pwd.h>
#include <signal.h>
#include <unistd.h>

static void my_alarm(int signo)
{
	struct passwd *rootptr;
	printf("in signal handler\n");
	if((rootptr=getpwnam("root"))==NULL)
		err_sys("getpwnam(root) error");
	alarm(1);
	puts("hwllo in signal");
}
int main(int argc,char *argv[])
{
	struct passwd *ptr;
	signal(SIGALRM,my_alarm);
	alarm(1);
	for(;;){
		if((ptr=getpwnam("jinux"))==NULL)
			err_sys("getpwnam error");
		puts("hwllo");
		if(strcmp(ptr->pw_name,"jinux")!=0)
			printf("return value corrupted!, pw_name = %s\n",ptr->pw_name);
	}


	return 0;
}

