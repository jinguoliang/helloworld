#include "ourhdr.h"
#include "errno.h"

int main(void)
{
	int fd;
	int pid;

	fd=open("test.tmp",O_RDWR);

	if((pid=fork())<0)
		err_sys("fork err");
	else{
		if(write_lock(fd, 10, SEEK_SET, 10)<0){
			if(errno==EAGAIN)
				printf("can't lock, it is locked by PID: %d\n", lock_test(fd,F_WRLCK,10,SEEK_SET,10));
			else
				err_quit("read_lock err");
		}
		else{
			puts("lock ok");
		}
	}
	sleep(10);
}
