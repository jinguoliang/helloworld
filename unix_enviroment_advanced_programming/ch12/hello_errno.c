#include <stdio.h>
#include <errno.h>
#include <string.h>

/**
*	what is the error,the local variable can't over the global????
*/
extern int errno;

int merrno=0;

void printerr(int e){
	int merrno=e;
	printf("the err is %s\n",strerror(merrno));
//	int errno=e;
//	printf("the err is %s\n",strerror(errno));
}

void main(void)
{
	printerr(8);
}
