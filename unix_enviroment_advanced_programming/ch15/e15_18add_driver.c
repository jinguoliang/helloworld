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
	FILE *fp11,*fp20;

	if(signal(SIGPIPE,sig_pipe)==SIG_ERR)
		err_sys("signal error");

	if(pipe(fd1)<0||pipe(fd2)<0)
		err_sys("pipe error");


	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0){
		close (fd1[0]);
		close (fd2[1]);

		fp11=fdopen(fd1[1],"w");
		if(fp11==NULL)
			perror("fdopen fd1[1] failed");
		fp20=fdopen(fd2[0],"r");
		if(fp20==NULL)
			perror("fdopen fd2[0] failed");

		if(setvbuf(fp11,NULL,_IOLBF,0)<0)
			err_sys("setvbuf error");
		if(setvbuf(fp20,NULL,_IOLBF,0)<0)
			err_sys("setvbuf error");

		while(fgets(line,MAXLINE,stdin)!=NULL){
			n=strlen(line);
//			if(write(fd1[1],line,n)!=n)
//				err_sys("write error to pipe");

			line[n]=0;
			if(fputs(line,fp11)==EOF)
				err_sys("fputs to fp11 error");

			if((fgets(line,MAXLINE,fp20))==NULL)
				err_sys("fgets error form fp20");
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
	

