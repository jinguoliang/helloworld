#include <stdio.h>
#include <unistd.h>


int main(void)
{
	puts("hello");
	if(chroot("/tmp/jinx/")<0)
		perror("err chroot");
	else
		puts("ok chroot");
}
