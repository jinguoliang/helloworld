#include "ourhdr.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000*500];

void set_f1(int fileno,int fl)
{
	fcntl(fileno,F_SETFL,fl);
}
void clr_fl(int fileno,int fl)
{
	fcntl(fileno,F_SETFL,0);
}

int main(void)
{
	int			ntowrite, nwrite;
	char		*ptr;

	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "read %d bytes\n",ntowrite);

	set_f1(STDOUT_FILENO,O_NONBLOCK);

	ptr = buf;
	while(ntowrite > 0){
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite,errno);

		if(nwrite > 0){
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}

	clr_fl(STDOUT_FILENO, O_NONBLOCK);

	exit(0);
}
