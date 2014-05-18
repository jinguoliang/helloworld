#include "ourhdr.h"
#include <fcntl.h>


int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;

	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;

	return (fcntl(fd, cmd, &lock));

}
pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;
	lock.l_type = type;
	lock.l_start = offset;
	lock.l_whence = whence;
	lock.l_len = len;

	if(fcntl(fd,F_GETLK,&lock)<0)
		err_sys("fcntl error");

	if(lock.l_type == F_UNLCK)
		return 0;
	
	return(lock.l_pid);
}

int lockfile(int fd)
{
	struct flock lock;

	lock.l_type = F_WRLCK;
	lock.l_start= 0;
	lock.l_whence=SEEK_SET;
	lock.l_len=0;

	return(fcntl(fd, F_SETLK, &lock));
}

void set_fl(int fd, int flags)
{
	int val;

	if((val=fcntl(fd, F_GETFL,0))<0)
		err_sys("fcntl F_GETFL error");
	
	val |= flags;

	if(fcntl(fd, F_SETFL, val)<0)
		err_sys("fcntl F_SETFL error");
}
