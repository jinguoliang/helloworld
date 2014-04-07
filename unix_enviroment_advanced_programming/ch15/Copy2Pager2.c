/*
*filename:	Copy2Pager2.c
*author: 	Jinux
*create:	2014年04月07日 星期一 10时23分05秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <sys/wait.h>

#define PAGER "${PAGER:-more}"

int main(int argc,char *argv[])
{
	char line[MAXLINE];
	FILE *fpin,*fpout;

	if(argc!=2)
		err_quit("usage: a.out <pathname>");
	if((fpin = fopen(argv[1],"r"))==NULL)
		err_sys("can't open %s", argv[1]);

	if((fpout= popen(PAGER,"w"))==NULL)
		err_sys("popen error");

	while(fgets(line,MAXLINE,fpin)!=NULL){
		if(fputs(line,fpout)==EOF)
			err_sys("fputs error to pipe");
	}

	if(ferror(fpin))
		err_sys("fgets error");
	if(fclose(fpout)==-1)
		err_sys("fclose error");

	return 0;
}

