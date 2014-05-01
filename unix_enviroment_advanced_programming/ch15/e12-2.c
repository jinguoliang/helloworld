/*
*filename:	e12.c
*author: 	Jinux
*create:	2014年04月27日 星期日 01时04分39秒
*提示:		真正的去享受过程,真正的去体会过程,然后,认真就来了,细心就来了,代码之美就来了,短小精悍就来了
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ourhdr.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


struct mymesg{
	long mtype;
	char mtext[512];
};
int main(int argc,char *argv[])
{
//	struct msgid_ds buf;
	key_t key=ftok("/home/mylocal/jinux/mygit/unix_enviroment_advanced_programming/ch15/e12.c",9);
	if(key==-1)
		err_sys("ftok error");
	printf("%d\n",key);
	int msgid=msgget(key,IPC_CREAT);
	if(msgid==-1)
		err_sys("msgget error");
	printf("%d\n",msgid);

//	if(msgctl(msgid,IPC_STAT,&buf)<0)
//		err_sys("msgctl error");
//	printf("msg number = %d\n",buf.msg_qnum);
	
	struct mymesg msg,msg1;
//	msg.mtype=1;
//	strcpy(msg.mtext,"hello world");
//	if(msgsnd(msgid,(void*)&msg,sizeof(struct mymesg),0)<0)
//		err_sys("msgsnd error");
	long n;
	scanf("%ld",&n);
	if(msgrcv(msgid,(void*)&msg1,sizeof(struct mymesg),0,n)<0)
		err_sys("msgsnd error");
	printf(msg1.mtext);
	


	return 0;
}

