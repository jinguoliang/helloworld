#include <stdio.h>

void func(void)
{
	puts("hello");
}

int main(void)
{
	void (*fp)(void);

	fp=func;
	(*fp)();
	(***fp)();

}
