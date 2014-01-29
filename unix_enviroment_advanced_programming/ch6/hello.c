#include <stdio.h>
#include <setjmp.h>

jmp_buf jmpbuffer;

void Hello()
{

	
	puts("world");
	puts("hello world");
	longjmp(jmpbuffer,1);
}
	
int main(void)
{

	setjmp(jmpbuffer);
	printf("");

}
