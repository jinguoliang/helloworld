/*
*filename:	add_driver.c
*author: 	Jinux
*create:	2014年04月07日 星期一 16时40分56秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"

static void sig_pipe(int);

int main(int argc,char *argv[])
{
	int n,fd1[2],fd2[2];
	pid_t pid;
	char line[MAXLINE];

	if(signal(SIGPIPE,sig_pipe)==SIG_ERR)
		err_sys("signal error");

	if(pipe(fd1)<0||pipe(fd2)<0)
		err_sys("pipe error");

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0){
		close (fd1[0]);
		close (fd2[1]);
		while(fgets(line,MAXLINE,stdin)!=NULL){
			n=strlen(line);
			if(write(fd1[1],line,n)!=n)
				err_sys("write error to pipe");
			if((n=read(fd2[0],line,MAXLINE))<0)
				err_sys("read error form pipe");
			if(n==0){
				err_msg("child closed pipe");
				break;
			}
			line[n]=0;
			if(fputs(line,stdout)==EOF)
				err_sys("fputs error");
		}
		if(ferror(stdin))
			err_sys("fgets error on stdin");
		exit(0);
	}else{
		close(fd1[1]);
		close(fd2[0]);
		if(fd1[0]!=STDIN_FILENO){
			if(dup2(fd1[0],STDIN_FILENO)!=STDIN_FILENO)
				err_sys("dup2 error to stdin");
			close(fd1[0]);
		}

		if(fd2[1]!=STDOUT_FILENO){
			if(dup2(fd2[1],STDOUT_FILENO)!=STDOUT_FILENO)
				err_sys("dup2 error to stdout");
			close(fd2[1]);
		}
		if(execl("./add2","add2",(char*)0)<0)
			err_sys("execl error");
	}

	return 0;
}

static void 
sig_pipe(int signo)
{
	printf("SIGPIPE caught\n");
	exit(1);
}
	

