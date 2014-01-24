#include "ourhdr.h"
#include <pwd.h>
#include <shadow.h>

int main()
{
	struct passwd *ptr;
	struct spwd		*shadowp;

	if((ptr=getpwnam("root"))==NULL)
		err_sys("getpwnam error");
	if((shadowp=getspnam("root"))==NULL)
		err_sys("getspnam error");

	printf("pw_passwd = %s\n",ptr->pw_passwd==NULL||ptr->pw_passwd[0]==0?"(null)" :ptr->pw_passwd);
	printf("sp_pwdp = %s\n",shadowp->sp_pwdp==NULL||shadowp->sp_pwdp[0]==0?"(null)" :shadowp->sp_pwdp);
	
	return 0;
}
