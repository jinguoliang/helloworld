#include "ourhdr.h"
#include <sys/utsname.h>

int main(void)
{
	struct utsname linux_info;

	if(uname(&linux_info)==-1)
		err_sys("uname error");
	
	printf("name = %s\n",linux_info.sysname);
	printf("nodename = %s\n",linux_info.nodename);
	printf("release = %s\n",linux_info.release);
	printf("version = %s\n",linux_info.version);
	printf("machine = %s\n",linux_info.machine);
}
