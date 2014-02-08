/*
*filename:	test_typedef.c
*author: 	Jinux
*create:	Wed 05 Feb 2014 10:42:40 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>

typedef void Func(void);

void hello(void)
{
	puts("hello");
}

int main(int argc,char *argv[])
{
	Func *func=hello;

	func();


	return 0;
}

