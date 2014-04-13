/*
*filename:	connect_retry.c
*author: 	Jinux
*create:	2014年04月10日 星期四 23时29分01秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <sys/socket.h>
#define MAXSLEEP 128

int
connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
	int nsec;

	for(nsec=1;nsec<=MAXSLEEP;nsec<<=1){
		if(connect(sockfd, addr, alen)==0){
			return(0);
		}

		if(nsec <= MAXSLEEP/2)
			sleep(nsec);
	}
	return -1;
}

