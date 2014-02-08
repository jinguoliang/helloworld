/*
*filename:	e3.2.c
*author: 	Jinux
*create:	Tue 04 Feb 2014 11:15:17 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	if((pid=fork())<0)
		perror("fork error");
	else if(pid==0){
		setsid();
		system("ps -o pid,ppid,pgid,sid,tpgid,cmd>child");
	}else{
		system("ps -o pid,ppid,pgid,sid,tpgid,cmd>parent");
		exit(0);
	}


	return 0;
}

