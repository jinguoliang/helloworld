/*
*filename:	test_memset.c
*author: 	Jinux
*create:	2014年04月28日 星期一 23时28分17秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char *area=(char*)malloc(sizeof(long));
//	memset(area,0,sizeof(long));
	printf("the area = %ld\n",*(long*)area);

	return 0;
}

