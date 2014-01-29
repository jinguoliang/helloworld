#include "ourhdr.h"

int main(void)
{
	long* la=calloc(8,sizeof(long));
	printf("Hello %ld %ld %ld %ld\n",la[0],la[2],la[4],la[6]);
	void* *pa=calloc(4,sizeof(void*));
	printf("%s\n",pa[2]==NULL?"NULL":"not NULL");
}
