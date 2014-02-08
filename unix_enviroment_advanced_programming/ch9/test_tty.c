/*
*filename:	test_tty.c
*author: 	Jinux
*create:	Mon 03 Feb 2014 09:33:41 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	char * s="hello world";
	int fid;
	if((fid=open("/dev/tty",O_WRONLY))<0)
		err_sys("open error");

	if(write(fid,s,12)!=12)
		err_sys("write error");

	printf("hello world from printf");
	
	return 0;
}

