/*
*filename:	exercise3.5.c
*author: 	Jinux
*create:	Wed 08 Jan 2014 11:34:26 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"

int main(int argc,char *argv[])
{
	char *str="hello world\n";
	char *err="bad world\n";

	write(STDOUT_FILENO,str,13);
	write(STDERR_FILENO,err,11);

	return 0;
}

