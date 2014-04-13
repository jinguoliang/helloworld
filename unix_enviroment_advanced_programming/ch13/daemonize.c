#include "ourhdr.h"
#include <syslog.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <sys/resource.h>

void daemonize(const char *cmd)
{
	int 				i,fd0,fd1,fd2;
	pid_t				pid;	
	struct rlimit 		rl;
	struct sigaction	sa;	
	int logfd;

	//clear file creation mask
	umask(0);

	//get maximum number of file descriptors
	if(getrlimit(RLIMIT_NOFILE,&rl)<0)
		err_quit("%s: can't get file limit",cmd);
	
	//become a session leader to lose controlling TTY
	if((pid=fork())<0)
		err_quit("%s: can't fork",cmd);
	else if(pid!=0){
		puts("parent die");
		exit(0);
	}
	puts("this is child");
	setsid();

	//ensure future opens won't allocate controlling TTYs.
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0;
	if(sigaction(SIGHUP,&sa,NULL)<0)
		err_quit("%s: can't ignore SIGHUP");
	if((pid=fork())<0)
		err_quit("%s: can't fork",cmd);
	else if(pid!=0){
		puts("parent die");
		exit(0);
	}
	puts("this is child");
	
	//change the current working directory to the root 
	if(chdir("/")<0)
		err_quit("%s: can't change directory to /");
	puts("chdir to /");

	puts("open log");
	//chroot
//	if(chroot("/tmp/")<0)
//		perror("err chroot");

	//close all open file descriptors.
	/*if(rl.rlim_max==RLIM_INFINITY)
		rl.rlim_max=1024;
	for(i=0;i<rl.rlim_max;i++)
		close(i);
	puts("open log");
	*/

	//attach file descriptors 0,1, and 2 to /dev/null
/*	fd0=open("/dev/null",O_RDWR);
	fd1=dup(0);
	fd2=dup(0);
	*/


	printf("really openlog?\n");
	//initialize the log file
	openlog(cmd,LOG_CONS,LOG_DAEMON);

	printf("really openlog\n");
}

/*void main(void)
{
	
	daemonize("ls");
	printf("daemonize ok\n");

	FILE *f=fopen("/home/CORPUSERS/xp013796/mygit/unix_enviroment_advanced_programming/ch13/log","w");
	fprintf(f,"the login name is %s\n",getlogin());
	fflush(f);

	syslog(LOG_DEBUG,"test it");
	

	closelog();
	
}
*/
