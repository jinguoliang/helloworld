/*
*filename:	revoke_U2l.c
*author: 	Jinux
*create:	2014年04月07日 星期一 14时25分01秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <sys/wait.h>

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	FILE *fpin;

	if((fpin=popen("myuclc","r"))==NULL)
		err_sys("popen error");

	for(;;){
		fputs("prompt> ",stdout);
		fflush(stdout);
		if(fgets(line,MAXLINE,fpin)==NULL)
			break;
		if(fputs(line,stdout)==EOF)
			err_sys("fputs errror to pipe");
	}
	if(pclose(fpin)==-1)
		err_sys("pclose  error");

	putchar('\n');

	return 0;
}

