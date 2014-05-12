#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


main()
{
	int fdout=open("/dev/console",O_WRONLY);

	write(fdout,"hello world",12);
}
