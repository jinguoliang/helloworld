#include <stdio.h>

int* test_static(void)
{
	static int  a=5;
	a++;
	return &a;
}
void main(void)
{
	int * i=test_static();
	printf("i = %d\n",*i);
	test_static();
	printf("i = %d\n",*i);

}
