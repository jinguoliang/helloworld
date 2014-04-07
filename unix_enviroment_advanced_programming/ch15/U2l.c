/*
*filename:	U2l.c
*author: 	Jinux
*create:	2014年04月07日 星期一 14时22分29秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <ctype.h>

int main(int argc,char *argv[])
{
	int 	c;
	while((c=getchar())!=EOF){
		if(isupper(c))
			c=tolower(c);
		if(putchar(c)==EOF)
			err_sys("output error");
		if(c=='\n')
			fflush(stdout);
	}

	return 0;
}

