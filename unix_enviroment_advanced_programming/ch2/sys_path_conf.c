/*
*filename:	sys_path_conf.c
*author: 	Jinux
*create:	Sun 05 Jan 2014 08:56:15 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <errno.h>
#include "ourhdr.h"

static void pr_sysconf(char *,int);
static void pr_pathconf(char *,char*,int);


int main(int argc,char *argv[])
{
	if( argc!=2)
		err_quit("usage: a.out <dirname>");

	pr_sysconf("ARG_MAX			=",_SC_ARG_MAX);
	pr_sysconf("CHILD_MAX		=",_SC_CHILD_MAX);

	pr_pathconf("MAX_INPUT		=","/dev/tty",_PC_MAX_INPUT);
	pr_pathconf("LINK_MAX		=",argv[1],_PC_LINK_MAX);
	pr_pathconf("NAME_MAX		=",argv[1],_PC_NAME_MAX);
	pr_pathconf("PATH_MAX		=",argv[1],_PC_PATH_MAX);

	return 0;
}

static void pr_sysconf(char *mesg,int name)
{
	long val;

	fputs(mesg,stdout);
	errno=0;
	if((val=sysconf(name))<0){
		if(errno!=0)
			err_sys("sysconf error");
		fputs(" (not defined)\n",stdout);
	}else
		printf(" %ld\n",val);
}

static void pr_pathconf(char *mesg,char *path,int name)
{
	long val;

	fputs(mesg,stdout);
	errno=0;
	if((val=sysconf(name))<0){
		if(errno!=0)
			err_sys("pathconf error, path = %s",path);
		fputs(" (not nolimit)\n",stdout);
	}else
		printf(" %ld\n",val);
}

