#include "ourhdr_db.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define FILE_MODE 0666

int main(void)
{
	DBHANDLE db;

	if((db = db_open("db4", O_RDWR|O_CREAT|O_TRUNC)) == NULL)
		err_sys("db_open error");

	if (db_store(db, "Alpha", "data1", DB_INSERT) != 0)
		err_quit("db_store error for alpha");
	if (db_store(db, "beta", "Data for beta", DB_INSERT) != 0)
		err_quit("db_store error for beta");
	if (db_store(db, "gamma", "record3", DB_INSERT) != 0)
		err_quit("db_store error for gamma");
//

//	test_db_readptr(db,4);;

	printf("-------the first is %s\n",db_fetch(db, "Alpha"));
	printf("-------the second is %s\n",db_fetch(db, "beta"));
	printf("-------the third is %s\n",db_fetch(db, "gamma"));

	db_close(db);

	exit(0);
}
