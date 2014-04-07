/*
*filename:	Copy2Pager.c
*author: 	Jinux
*create:	2014年04月07日 星期一 09时30分22秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <sys/wait.h>

#define DEF_PAGER "/bin/more"

int main(int argc,char *argv[])
{
	int n;
	int fd[2];
	pid_t pid;
	char *pager,*argv0;
	char line[MAXLINE];
	FILE *fp;

	if(argc!=2)
		err_quit("usage: a.out <pathname>");

	if((fp=fopen(argv[1],"r"))==NULL)
		err_sys("can't open %s",argv[1]);
	if(pipe(fd)<0)
		err_sys("pipe error");

	if((pid=fork())<0)
		err_sys("fork error");
	else if(pid>0){
		close(fd[0]);

		while(fgets(line,MAXLINE,fp)!=NULL){
			n=strlen(line);
			if(write(fd[1],line,n)!=n)
				err_sys("write error to pipe");
		}
		if(ferror(fp))
			err_sys("fgets error");

		close(fd[1]);

		if(waitpid(pid,NULL,0)<0)
			err_sys("waitpid error");
	}else{
		close(fd[1]);

		if(fd[0]!=STDIN_FILENO){
			if(dup2(fd[0],STDIN_FILENO)!=STDIN_FILENO)
				err_sys("dup2 error to stdin");
			close(fd[0]);
		}

		if((pager=getenv("PAGER"))==NULL)
			pager=DEF_PAGER;
		if((argv0=strrchr(pager,'/'))!=NULL)
			argv0++;
		else
			argv0=pager;

		if(execl(pager,argv0,(char*)0)<0)
			err_sys("execl error for %s",pager);
	}


	return 0;
}

