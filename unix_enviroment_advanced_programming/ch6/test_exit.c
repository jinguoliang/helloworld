#include "ourhdr.h"

typedef void (*ExitFunc)(void);

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	ExitFunc exitfunc=my_exit2;
	if(atexit(exitfunc)!=0)
		err_sys("can't register my_exit2");

	exitfunc=my_exit1;
	if(atexit(exitfunc)!=0)
		err_sys("can't register my_exit1");

	if(atexit(exitfunc)!=0)
		err_sys("can't register my_exit1");

	printf("main is done\n");
	return 0;
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}

static void my_exit2(void)
{
	printf("second exit handler\n");
}
