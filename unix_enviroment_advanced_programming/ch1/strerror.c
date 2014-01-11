/*
*filename:	strerror.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 10:36:18 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <errno.h>
#include "ourhdr.h"

int main(int argc,char *argv[])
{
	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));

	errno = ENOENT;
	perror(argv[0]);
	printf("%s\n",rerror(2));


	return 0;
}

