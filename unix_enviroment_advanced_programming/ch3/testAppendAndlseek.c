/*
*filename:	testAppendAndlseek.c
*author: 	Jinux
*create:	Wed 08 Jan 2014 11:56:14 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <fcntl.h>

int main(int argc,char *argv[])
{
	int fd;
	char buf[5];

	if((fd=open("tmp.foo",O_RDWR|O_APPEND))<0)
		err_sys("open failed");
	lseek(fd,0,SEEK_SET);
	read(fd,buf,5);
	write(1,buf,5);
	write(fd,"jin",3);


	return 0;
}

