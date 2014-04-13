/*
*filename:	getuptime_server.c
*author: 	Jinux
*create:	2014年04月11日 星期五 00时05分00秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include "ourhdr.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>


#define BUFLEN 128
#define QLEN	10

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

extern int initserver(int,struct sockaddr *,socklen_t,int);

void
serve(int sockfd)
{
	int clfd;
	FILE *fp;
	char buf[BUFLEN];

	for(;;){
		puts("wait client....");
		clfd=accept(sockfd,NULL,NULL);
		if(clfd<0){
			syslog(LOG_ERR,"ruptimed: accept error: %s",strerror(errno));
			exit(1);
		}
		if((fp=popen("/usr/bin/uptime","r"))==NULL){
			sprintf(buf,"error: %s\n",strerror(errno));
			send(clfd,buf,strlen(buf),0);
		}else{
			while(fgets(buf,BUFLEN,fp)!=NULL)
				send(clfd,buf,strlen(buf),0);
			pclose(fp);
		}
		close(clfd);
	}
	puts("server end");
}

int main(int argc,char *argv[])
{
	struct addrinfo *ailist,*aip;
	struct addrinfo hint;
	int sockfd,err,n;
	char host[64];

	if(argc != 1)
		err_quit("usage: ruptimed");
#ifdef _SC_HOST_NAME_MAX
	n=sysconf(_SC_HOST_NAME_MAX);
	if(n<0)
#endif
		n=HOST_NAME_MAX;
//	host=malloc(n);
//	if(host=NULL)
//		err_sys("malloc error");
	if(gethostname(host,n)<0)
		err_sys("gethostname error");
	daemonize("ruptimed");
	puts("daemonize ok");
	hint.ai_flags=AI_CANONNAME;
	hint.ai_socktype=SOCK_STREAM;
	hint.ai_family=0;
	hint.ai_protocol=0;
	hint.ai_addrlen=0;
	hint.ai_addr=NULL;
	hint.ai_next=NULL;
	hint.ai_canonname=NULL;
	printf("hint\n");
	if((err=getaddrinfo(host,"ruptime",&hint,&ailist))!=0){
		printf("ruptimed: getaddrinfo error: %s\n",gai_strerror(err));
		printf("getaddrinfo error\n");
		exit(1);
	}
	for(aip=ailist;aip!=NULL;aip=aip->ai_next){
		if((sockfd=initserver(SOCK_STREAM,aip->ai_addr,aip->ai_addrlen,QLEN))>=0){
			serve(sockfd);
			printf("exit\n");
			exit(0);
		}else{
			perror("initserver error");
		}
	}
	
	printf("no address?\n");

	return 0;
}

