//gcc ./test_restrict.c -std=c99

#include <stdio.h>

void foo(int  *restrict n)
{
	*n=5;
	int *np=n;
	*np=8;
}
int main(void)
{
	int n=5;
	foo(&n);

}

