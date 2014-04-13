/*
*filename:	getuptime_client.c
*author: 	Jinux
*create:	2014年04月13日 星期日 16时18分28秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAXADDRLEN 256
#define BUFLEN 128

extern int connect_retry(int, const struct sockaddr *, socklen_t);

void print_uptime(int sockfd)
{
	int n;
	char buf[BUFLEN];
	while ((n = recv(sockfd, buf, BUFLEN, 0)) > 0)
		write(STDOUT_FILENO, buf, n);
	if (n < 0)
		puts("recv error");
}

int main(int argc, char *argv[])
{
	struct addrinfo *ailist, *aip;

	struct addrinfo hint;
	int sockfd, err;

	if (argc != 2)
		puts("usage: ruptime hostname");

	hint.ai_flags = 0;
	hint.ai_family = 0;
	hint.ai_socktype = SOCK_STREAM;
	hint.ai_protocol = 0;
	hint.ai_addrlen = 0;
	hint.ai_canonname = NULL;
	hint.ai_addr = NULL;
	hint.ai_next = NULL;
	puts("getaddrinfo");
	if ((err = getaddrinfo(argv[1], "ruptime", &hint, &ailist)) != 0)
		printf("getaddrinfo error: %s", gai_strerror(err));
	for (aip = ailist; aip != NULL; aip = aip->ai_next) {
		puts("new socket");
		if ((sockfd = socket(aip->ai_family, SOCK_STREAM, 0)) < 0)
			err = errno;
		puts("connect");
		if (connect_retry(sockfd, aip->ai_addr, aip->ai_addrlen) < 0) {
			err = errno;
		} else {
			print_uptime(sockfd);
			exit(0);
		}
	}
	fprintf(stderr, "can't connect to %s: %s\n", argv[1], strerror(err));
	exit(1);
}
