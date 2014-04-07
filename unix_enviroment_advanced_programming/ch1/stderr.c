/*
*filename:	stderr.c
*author: 	Jinux
*create:	Sat 04 Jan 2014 08:25:57 PM CST
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"

static void err_doit(int merrnoflag, int merrno, const char *fmt, va_list ap)
{
	char buf[MAXLINE];

	vsprintf(buf, fmt, ap);
	if (merrnoflag)
		sprintf(buf + strlen(buf), ":%s", strerror(merrno));
	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(NULL);

	return;
}

char *pname = NULL;

void err_sys(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_quit(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_exit(int merrno, const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, merrno, fmt, ap);
	va_end(ap);
	exit(1);
}

void err_dump(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort();
	exit(1);
}

void err_ret(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	return;
}

void err_msg(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, 0, fmt, ap);
	va_end(ap);
	return;
}


void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
		       WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination,signal number = %d%s\n",
		       WTERMSIG(status),
#ifdef WCOREDUMP
		       WCOREDUMP(status) ? " (core file generated)" : "");
#else
		       "");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
