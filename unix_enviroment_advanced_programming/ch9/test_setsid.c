/*
*filename:	test_setsid.c
*author: 	Jinux
*create:	Mon 03 Feb 2014 08:45:36 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <unistd.h>

int main(int argc,char *argv[])
{
	pid_t sid;
	if((sid=setsid())<0)
		err_sys("setsid error");
	printf("sid = %d\n",sid);
	system("ps -o pid,ppid,pgid,sid,cmd");


	return 0;
}

