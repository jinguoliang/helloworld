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
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXLINE 4096

void err_sys (const char *fmt, ...);
void err_quit (const char *fmt, ...);
void err_ret (const char *fmt, ...);
void err_exit(int ,const char *fmt, ...);
void pr_exit(int status);

//file lock
int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len);
pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len);

//file lock
#define read_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_RDLCK, (offset), (whence), (len))
#define readw_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLKW, F_RDLCK, (offset), (whence), (len))
#define write_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_WRLCK, (offset), (whence), (len))
#define writew_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
#define un_lock(fd, offset, whence, len) \
			lock_reg((fd), F_SETLK, F_UNLCK, (offset), (whence), (len))

#define is_read_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_RDLCK, (offset), (whence), (len))==0)
#define is_write_lockable(fd, offset, whence, len) \
			(lock_test((fd), F_WRLCK, (offset), (whence), (len))==0)
int lockfile(int fd);
void set_fl(int fd, int flags);

//TELL WAIT
void TELL_WAIT(void);
void TELL_PARENT(pid_t pid);
void WAIT_PARENT(void);
void TELL_CHILD(pid_t pid);
void WAIT_CHILD(void);


#endif
