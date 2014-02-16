/*
*filename:	my_system.c
*author: 	Jinux
*create:	2014年02月16日 星期日 21时46分09秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system_j(const char*cmdstring)
{
	pid_t pid=0;
	int status=0;
	
	if(cmdstring==NULL)
		return 1;

	if((pid=fork())<0)
		status=-1;
	else if(pid==0){
		execlp("sh","sh","-c",cmdstring,(char*)NULL);
		_exit(127);
	}else {
		while(waitpid(pid,&status,0)<0){
			if(errno!=EINTR){
				status=-1;
				break;
			}
		}
	}

	return status;
}

void child_handler(int signo)
{
	puts("childe finished");
}

int main(int argc,char *argv[])
{
	if(signal(SIGCHLD,child_handler)<0)
		perror("SIGCHLD error");

	if(system_j("ed")==-1);
		perror("system error");
	puts("hello world");

	return 0;
}

