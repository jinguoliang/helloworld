/*
*filename:	mycp1.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 09:02:38 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"


int main(int argc,char *argv[])
{
	int c;
	while ((c=getc(stdin))!=EOF)
		if(putc(c,stdout)==EOF)
			err_sys("output error");

	if(ferror(stdin))
		err_sys("input error");

	return 0;
}

