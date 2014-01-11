/*
*filename:	setflag.c
*author: 	Jinux
*create:	Wed 08 Jan 2014 10:46:25 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <fcntl.h>
#include "ourhdr.h"

void set_fl(int fd,int flags)
{
	int val;

	if((val=fcntl(fd,F_GETFL,0))<0)
		err_sys("fcntl F_GETFL error");
	
	val |= flags;

	if(fcntl(fd,F_SETFL,val) <0)
		err_sys("fcntl F_SETFL error");
}

void clr_fl(int fd,int flags)
{
	int val;

	if((val=fcntl(fd,F_GETFL,0))<0)
		err_sys("fcntl F_GETFL error");
	
	val &= ~flags;

	if(fcntl(fd,F_SETFL,val) <0)
		err_sys("fcntl F_SETFL error");
}

int main(int argc,char *argv[])
{

	int n;
	char buf[BUFSIZ];

//	set_fl(STDOUT_FILENO,O_SYNC);

	while((n=read(STDIN_FILENO,buf,BUFSIZ))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	
	if(n<0)
		err_sys("read error");
}

