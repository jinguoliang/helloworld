/*
*filename:	mycp.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 08:53:02 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#define BUFSIZ 8192

int main(int argc,char *argv[])
{
	int n;
	char buf[BUFSIZ];

	while((n=read(STDIN_FILENO,buf,BUFSIZ))>0)
		if(write(STDOUT_FILENO,buf,n)!=n)
			err_sys("write error");
	
	if(n<0)
		err_sys("read error");


	return 0;
}

