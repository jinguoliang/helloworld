#include "ourhdr.h"
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>

#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

extern int lockfile(int);

int already_running(void)
{
	int 	fd;
	char	buf[16];

	fd=open(LOCKFILE,O_RDWR|O_CREAT,LOCKMODE);
	if(fd<0){
		perror("open failed");
		syslog(LOG_ERR,"can't open %s: %s",LOCKFILE,strerror(errno));
		exit(1);
	}
	puts("opened file");
	if(lockfile(fd)<0){
		puts("lockfile <0");
		if(errno==EACCES||errno==EAGAIN){
			if(errno==EACCES)
				puts("errno == EACCES");
			if(errno==EAGAIN)
				puts("errno == EAGAIN");
			close(fd);
			return 1;
		}
		syslog(LOG_ERR,"can't lock %s: %s",LOCKFILE,strerror(errno));
		exit(1);
	}
	ftruncate(fd,0);
	sprintf(buf,"%ld",(long)getpid());
	write(fd,buf,strlen(buf)+1);
	return 0;
}

int main(void)
{
	puts("in main");
	if(already_running())
		puts("already_running");
	else
		puts("no running");
	
}
