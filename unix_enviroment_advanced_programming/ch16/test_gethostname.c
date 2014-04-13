/*
*filename:	test_gethostname.c
*author: 	Jinux
*create:	2014年04月12日 星期六 00时01分58秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <sys/socket.h>
#include <netdb.h>

int main(int argc,char *argv[])
{

	 char hostname[64];
	 char *servname="echo";
	 struct addrinfo hint,*res;
	 int err;

	 if(gethostname(hostname,64)!=-1)
		 puts(hostname);

	 hint.ai_socktype=SOCK_STREAM;
	 hint.ai_addr=NULL;
	 hint.ai_addrlen=0;
	 hint.ai_protocol=0;
	 hint.ai_family=0;
	 hint.ai_flags=0;
	 hint.ai_canonname=NULL;
	 hint.ai_next=NULL;

	 if((err=getaddrinfo(hostname,servname,&hint,&res))!=0){
		 err_sys("getaddrinfo errrors");
	 }

	 while(res!=NULL){
		 if(initserver(res->ai_socktype,res->ai_addr,res->ai_addrlen,24)<0)
			 perror("init not ok");
		 else{
			 puts("has one");
			 exit(0);
		 }
		 res=res->ai_next;
	 }
	 puts("has no one");







	return 0;
}

