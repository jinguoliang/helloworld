#include "ourhdr.h"
#include <fcntl.h>

#define BUFSIZ 1

int main(int argc,char* argv[])
{
	char buf[BUFSIZ];
	int n;
	int sf_no,df_no;

	if (argc<3){
		printf("Usage: %s source target\n",argv[0]); 
		exit(0);
	}

	int mask=umask(0002);
	printf("the mask is %o",mask);

	if((sf_no=open(argv[1],O_RDONLY))<0)
		err_sys("open %s err",argv[1]);
	if((df_no=open(argv[2],O_CREAT|O_WRONLY,S_IRWXU|S_IRWXG|S_IRWXO))<0)
		err_sys("open %s err",argv[1]);

	while((n=read(sf_no,&buf,BUFSIZ))>0){
		if(buf[0]==0)
			continue;
		if(write(df_no,&buf,n)<0)
			err_sys("write err");
	}
	if(n<0)
		err_sys("read err");

	return 0;
}

