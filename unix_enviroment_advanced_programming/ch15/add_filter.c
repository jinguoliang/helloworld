/*
*filename:	add_filter.c
*author: 	Jinux
*create:	2014年04月07日 星期一 16时33分46秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"

int main(int argc,char *argv[])
{
	int n,int1,int2;
	char line[MAXLINE];

	while((n=read(STDIN_FILENO,line,MAXLINE))>0){
		line[n]=0;
		if(sscanf(line,"%d%d",&int1,&int2)==2){
			sprintf(line,"%d\n",int1+int2);
			n=strlen(line);
			if(write(STDOUT_FILENO,line,n)!=n)
				err_sys("write error");
		}else{
			if(write(STDOUT_FILENO,"invalid args\n",13)!=13)
				err_sys("write error");
		}
	}

	return 0;
}

