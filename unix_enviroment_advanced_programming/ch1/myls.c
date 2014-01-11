/*
*filename:	myls.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 08:13:28 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <sys/types.h>
#include <dirent.h>
#include "ourhdr.h"

int main(int argc,char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
		err_quit("a single is required");

	if ((dp=opendir(argv[1]))==NULL)
		err_sys("can't open %s",argv[1]);
	
	while((dirp=readdir(dp))!=NULL)
		printf("%s\n",dirp->d_name);
	
	closedir(dp);

	return 0;
}

