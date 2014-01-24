#include <pwd.h>
#include <sys/types.h>
#include <string.h>
#include "ourhdr.h"

struct passwd* my_getpwnam(const char *name)
{
	struct passwd *ptr;

	setpwent();
	while((ptr=getpwent())!=NULL)
		if(strcmp(name,ptr->pw_name)==0)
			break;
	endpwent();
	return(ptr);
}

void main(int argc,char *argv[])
{
	struct passwd *ptr;

	if(argc!=2)
		err_quit("Usage: %s username",argv[0]);

	puts(argv[1]);

	ptr=my_getpwnam(argv[1]);

	if(ptr!=NULL){
		printf("the name is %s\n",ptr->pw_name);
		printf("the uid is %d\n",ptr->pw_uid);
		printf("the gid is %d\n",ptr->pw_gid);
		printf("the dir is %s\n",ptr->pw_dir);
		printf("the shell is %s\n",ptr->pw_shell);
	}else{
		perror("no such username");
	}
}
