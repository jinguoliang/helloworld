/*
*filename:	PtoC_pipe.c
*author: 	Jinux
*create:	2014年04月07日 星期一 09时21分17秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include "ourhdr.h"

int main(int argc,char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];

	if(pipe(fd)<0)
		perror("pipe error");
	if((pid=fork())<0)
		perror("fork error");
	else if(pid>0){
		close(fd[0]);
		write(fd[1],"hello world\n",12);
	}else{
		close(fd[1]);
		n=read(fd[0],line,MAXLINE);
		write(STDOUT_FILENO,line,n);
	}


	return 0;
}

