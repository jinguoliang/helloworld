/*
*filename:	ls.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 06:16:51 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>


int main(int argc,char *argv[])
{
	DIR *dir;
	struct dirent *dirent;

	dir=opendir(argv[1]);
	if(dir!=NULL){
		dirent=readdir(dir);
		while(dirent != NULL){
			puts(dirent->d_name);
			dirent=readdir(dir);
		}
	}
	closedir(dir);
	return 0;
}

