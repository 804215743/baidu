#include "my.h"

int g=10;

int main()
{
	int l=20;
	int status;
	static int s=30;
	pid_t pid;
	pid=vfork();
	if(pid < 0)
	{
		perror("failed to fork!\n");
		return -1;
	}
	else if(pid==0)
	{
		//int p=99;
		printf("-------address of var-------\n");
		printf("child pid= %d\n&g=%16p\n&l=%16p\n&s=%16p\n",getpid(),&g,&l,&s);
		g=100;
		l=200;
		s=300;
		//p=99999;
		execl("./test6","test6",NULL);
		printf("value in child\n");
		printf("g=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;
		//exit(119);
		//_exit(0);
	}
	else 
	{
		//wait(&status);
		//printf("parent :exit code from chile is %d\n",WEXITSTATUS(status));		
		printf("-------address of var in parent-------\n");
		printf("parent: &g=%16p\n&l=%16p\n&s=%16p\n",&g,&l,&s);
		printf("value in parent\n");
		printf("parent: g=%d\nl=%d\ns=%d\n",g,l,s);
		return 0;

	}


}
