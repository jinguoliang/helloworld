/*
*filename:	initserver.c
*author: 	Jinux
*create:	2014年04月10日 星期四 23时42分39秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <errno.h>
#include <sys/socket.h>

#define ML(str) puts(str)

int 
initserver(int type,const struct sockaddr *addr,socklen_t alen,int qlen)
{
	int fd;
	int err=0;

	ML("initserver");
	if((fd=socket(addr->sa_family,type,0))<0)
		return(-1);
	ML("binding");
	if(bind(fd,addr,alen)<0){
		err=errno;
		goto errout;
	}
	ML("listen");
	if(type==SOCK_STREAM || type==SOCK_SEQPACKET){
		if(listen(fd,qlen)<0){
			err=errno;
			goto errout;
		}
	}
	ML("ok return ");
	return(fd);

errout:
	close(fd);
	errno=err;
	ML("not ok ");
	return(-1);
}

