/*
*filename:	show_time.c
*author: 	Jinux
*create:	Fri 31 Jan 2014 09:07:19 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <stdio.h>
#include <stdlib.h>

static void pr_times(clock_t real,struct tms*tmsStart,struct tms*tmsEnd)
{
	static long clktck=0;

	if(clktck == 0)
		if((clktck=sysconf(_SC_CLK_TCK))<0)
			err_sys("sysconf error");
	printf(" real: %7.2f\n",real/(double)clktck);
	printf(" user: %7.2f\n",(tmsEnd->tms_utime-tmsStart->tms_utime)/(double)clktck);
	printf(" sys: %7.2f\n",(tmsEnd->tms_stime-tmsStart->tms_stime)/(double)clktck);
	printf(" child user: %7.2f\n",(tmsEnd->tms_cutime-tmsStart->tms_cutime)/(double)clktck);
	printf(" child sys: %7.2f\n",(tmsEnd->tms_cstime-tmsStart->tms_cstime)/(double)clktck);
}
static void do_cmd(char *cmd)
{
	time_t userTime;
	time_t sysTime;
	time_t startTime;
	time_t endTime;
	struct tms tmsStart,tmsEnd;

	if(starttime=times(&tms)<0)
		err_sys("times error");

	if(system(cmd)==-1)
		err_sys("system error");

	if(endTime=times(&tms)<0)
		err_sys("times error");
	pr_times(endTime-startTime,&tmsStart,&tmsEnd);
	pr_exit(status);
}
int main(int argc,char *argv[])
{
	int i;

	if(argc<2)
		err_quit("Usage: %s strcmd1 strcmd2 ...",argv[0]);
	
	setbuf(stdout, NULL);
	for(i=1;i<argc;i++){
		do_cmd(argv[i]);
	}
			

	return 0;
}

