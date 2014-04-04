#include "ourhdr.h"

main()
{
	char buf[1];
	int fd=open("./test.tmp",O_RDWR);

	buf[1]='c';

	write(fd,buf,1);
	write_lock(fd, -1, SEEK_END, 0);
	write(fd,buf,1);
	un_lock(fd, 0, SEEK_END,0);
	write(fd,buf,1);

	if(fork()==0){
		if(is_write_lockable(fd, -2, SEEK_END, 1))
			puts("the last third is not locked");
		else
			puts("the last third is locked");

		if(is_write_lockable(fd, -1, SEEK_END, 1))
			puts("the last third is not locked");
		else
			puts("the last third is locked");

		if(is_write_lockable(fd, -0, SEEK_END, 1))
			puts("the last third is not locked");
		else
			puts("the last third is locked");

	}
}
