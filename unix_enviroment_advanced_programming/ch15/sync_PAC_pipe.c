/*
*filename:	sync_PAC_pipe.c
*author: 	Jinux
*create:	2014年04月07日 星期一 10时04分00秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"

static int pfd1[2],pfd2[2];

void TELL_WAIT(void)
{
	if(pipe(pfd1)<0||pipe(pfd2)<0)
		err_sys("pipe error");
}

void TELL_PARENT(pid_t pid)
{
	if(write(pfd2[1],"c",1)!=1)
		err_sys("write error");
}

void WAIT_PARENT(void)
{
	char c;

	if(read(pfd1[0],&c,1)!=1)
		err_sys("read error");

	if(c!='p')
		err_quit("WAIT_PARENT: incorrect data");
}

void TELL_CHILD(pid_t pid)
{
	if(write(pfd1[1],"p",1)!=1)
		err_sys("write error");
}

void WAIT_CHILD(void)
{
	char c;
	if(read(pfd2[0],&c,1)!=1)
		err_sys("read error");

	if(c!='c')
		err_quit("WAIT_CHILD: incorrect data");
}
