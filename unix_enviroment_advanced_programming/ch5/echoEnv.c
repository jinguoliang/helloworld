#include <stdio.h>



char a[5]={1,1,1,1,};
int main(void)
{
	extern char **environ;
	char **p=environ;

	while(*p!=NULL)
		puts(*p++);
}
