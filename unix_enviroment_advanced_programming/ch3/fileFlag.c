/*
*filename:	fileFlag.c
*author: 	Jinux
*create:	Wed 08 Jan 2014 09:30:35 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <sys/types.h>
#include <fcntl.h>
#include "ourhdr.h"


int main(int argc,char *argv[])
{
	int accmode,val;
	if(argc!=2)
		err_quit("usage: a.out <descriptor#>");
	
	if((val=fcntl(atoi(argv[1]),F_GETFL,0))<0)
		err_sys("fcntl error for  fd %d",atoi(argv[1]));
	
	accmode=val&O_ACCMODE;
	if 			(accmode==O_RDONLY)	printf("read only");
	else if 	(accmode==O_WRONLY) printf("write only");
	else if 	(accmode==O_RDWR)	printf("Read Write");
	else err_dump("unknow access mod");

	if(val&O_APPEND)				printf(",append");
	if(val&O_NONBLOCK)				printf(",noblocking");
#if !defined(_POSIX_SOURCE) && defined(O_SYNC)
	if(val&O_SYNC)					printf(",synchronous writes");
#endif
	putchar('\n');

	return 0;
}

