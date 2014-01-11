/*
*filename:	myexec.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 09:24:28 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <sys/types.h>
#include <sys/wait.h>
#include "ourhdr.h"


int main(int argc,char *argv[])
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while(fgets(buf,MAXLINE,stdin)!=NULL){
		buf[strlen(buf)-1]=0;

		if((pid=fork())<0)
			err_sys("fork err");

		else if(pid==0){
			execlp(buf,buf,(char*)0);
			err_ret("couldn't execute: %s",buf);
			exit(127);
		}

		if((pid=waitpid(pid,&status,0))<0)
			err_sys("waitpid error");
		printf("%% ");
	}

	return 0;
}

