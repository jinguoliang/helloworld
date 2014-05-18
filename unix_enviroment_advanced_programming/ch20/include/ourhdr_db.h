/*
*filename:	ourhdr_db.h
*author: 	Jinux
*create:	2014年05月17日 星期六 19时26分33秒
*提示:	作为一个头文件,就应该是一个接口,暴露该暴露的,隐藏该隐藏的
*/

#ifndef __OURHDR_DB_H__
#define __OURHDR_DB_H__

typedef 	void * 	DBHANDLE;

DBHANDLE 	db_open(const char *pathname,int oflag, .../*int mode*/);
void 		db_close(DBHANDLE db);
int 		db_store(DBHANDLE db,const char *key, const char *data, int flag);
char		*db_fetch(DBHANDLE db, const char *key);
int			db_delete(DBHANDLE db, const char *key);
void 		db_rewind(DBHANDLE db);
char		*db_nextrec(DBHANDLE db, char *key);

/*Flags for db_store*/
#define	DB_INSERT 	 0
#define	DB_REPLACE 	 1
#define	DB_STORE	 2

/*Implemention limits.
 */
#define IDXLEN_MIN		6		/*key, sep, start, sep, length, \n*/ 
#define IDXLEN_MAX		1024	
#define DATLEN_MIN		2		/*data byte, newline*/
#define DATLEN_MAX		1024	


#endif



