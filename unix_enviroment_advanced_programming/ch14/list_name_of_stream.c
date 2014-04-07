#include "ourhdr.h"
#include <fcntl.h>
#include <stropts.h>

int main(int argc, char *argv[])
{
	int 		fd, i, nmods;
	struct str_list list;

	if(argc!=2)
		err_quit("usage: %s <pathname>", argv[0]);

	if((fd=open(argv[1], O_RDONLY))<0)
		err_sys("can't open %s",argv[1]);
//	if(isastream(fd)==0)
//		err_quit("%s is not a stream",argv[1]);

	if((nmods = ioctl(fd, I_LIST, (void*) 0))<0)
		err_sys("I_LIST error for nmods");
	printf("#modules = %d\n",nmods);

}
