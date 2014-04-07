/*
*filename:	popen_m.c
*author: 	Jinux
*create:	2014年04月07日 星期一 10时41分33秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/wait.h>

#define PUTS //puts
static pid_t *childpid=NULL;

static int maxfd;

#ifdef OPEN_MAX
static long openmax=OPEN_MAX;
#else
static long openmax=0;
#endif

#define OPEN_MAX_GUESS 256

long open_max()
{
	if(openmax==0){
		errno=0;
		if((openmax=sysconf(_SC_OPEN_MAX))<0){
			if(errno==0)
				openmax=OPEN_MAX_GUESS;
			else
				err_sys("sysconf error for _SC_OPEN_MAX");
		}
	}
	return(openmax);
}

FILE *
popen(const char *cmdstring,const char *type)
{
	int i;
	int pfd[2];
	pid_t pid;
	FILE *fp;

	PUTS("popen start");
	if((type[0]!='r' && type[0]!='w')||type[1]!=0){
		errno=EINVAL;
		return(NULL);
	}

	if(childpid == NULL){
		maxfd=open_max();
		if((childpid=calloc(maxfd,sizeof(pid_t)))==NULL)
			return(NULL);
	}
	PUTS("popen open_max");

	if(pipe(pfd)<0)
		return(NULL);

	PUTS("popen pipe");
	if((pid=fork())<0){
		return(NULL);
	}else if(pid==0){
		PUTS("popen child start");
		if(*type=='r'){
			close(pfd[0]);
			if(pfd[1]!=STDOUT_FILENO){
				dup2(pfd[1],STDOUT_FILENO);
				close(pfd[1]);
			}
		}else{
			close(pfd[1]);
			if(pfd[0]!=STDIN_FILENO){
				dup2(pfd[0],STDIN_FILENO);
				close(pfd[0]);
			}
		}

		PUTS("popen child dup2");


		for(i=0;i<maxfd;i++)
			if(childpid[i]>0)
				close(i);
		PUTS("popen child close");

		execl("/bin/sh","sh","-c",cmdstring,(char*)0);
		_exit(127);
	}
	PUTS("popen parent start");

	if(*type=='r'){
		close(pfd[1]);
		if((fp=fdopen(pfd[0],type))==NULL)
			return(NULL);
	}else{
		close(pfd[0]);
		if((fp=fdopen(pfd[1],type))==NULL)
			return(NULL);
	}
	PUTS("popen parent close");

	childpid[fileno(fp)]=pid;
	return(fp);
}

int 
pclose(FILE *fp)
{
	int fd,stat;
	pid_t pid;

	if(childpid==NULL){
		errno=EINVAL;
		return(-1);
	}

	fd=fileno(fp);
	if((pid=childpid[fd])==0){
		errno=EINVAL;
		return(-1);
	}

	childpid[fd]=0;
	if(fclose(fp)==EOF)
		return(-1);

	while(waitpid(pid,&stat,0)<0)
		if(errno!=EINTR)
			return(-1);

	return(stat);
}

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	PUTS("start");
	FILE *fp=popen("ls","r");
	if(fp==NULL)
		err_sys("popen error");
	

	PUTS("read");
	while(fgets(line,MAXLINE,fp)!=NULL)
		printf(line);
	PUTS("end");
	

	pclose(fp);

	return 0;
}

