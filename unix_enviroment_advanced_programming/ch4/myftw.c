#include <limits.h>
#include "ourhdr.h"

typedef int Myfunc(const char*,const struct stat *,int );

static Myfunc       myfunc;
static int          myftw(char*,Myfunc*); 
static int          dopath(Myfunc*);

static long nreg,ndir,nblk,nchr,nfifo,nslink,nsock,ntot;

int main(int argc,char *argv[])
{
   myfunc(8,) 
   printf("hello");
   puts("hello");
   sprintf("hello");

    
    
}
