/*
*filename:	add_driver2.c
*author: 	Jinux
*create:	2014年04月07日 星期一 17时21分20秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <string.h>

int main(int argc,char *argv[])
{
	int int1,int2;
	char line[MAXLINE];

	while(fgets(line,MAXLINE,stdin)!=NULL){
		if(sscanf(line,"%d %d",&int1,&int2)==2){
			if(printf("%d\n",int1+int2)==EOF){
				err_sys("printf error");
			}
			fflush(stdout);
		}else{
			if(printf("invalid args\n")==EOF)
				err_sys("printf error");
		}
	}

	return 0;
}

