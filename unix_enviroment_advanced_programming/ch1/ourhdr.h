/*
*filename:	ourhdr.h
*author: 	Jinux
*create:	Sat 04 Jan 2014 08:22:38 PM CST
*提示:	作为一个头文件,就应该是一个接口,暴露该暴露的,隐藏该隐藏的
*/

#ifndef __OURHDR_H__
#define __OURHDR_H__

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096

void err_sys (const char *fmt, ...);
void err_quit (const char *fmt, ...);
void err_ret (const char *fmt, ...);
void err_exit(int ,const char *fmt, ...);
void pr_exit(int status);




#endif
