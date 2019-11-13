#include "my.h"


static void callback1(void)
{
	printf("-------callback1!-------\n");
}
static void callback2(void)
{
	printf("-------callback2!-------\n");
}
static void __attribute__((constructor)) before_main()
{
	printf("-------Before Main!-------\n");
}
static void __attribute__((constructor)) after_main()
{
	printf("-------After Main!-------\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"fputs use full buffer!"};
	if((fp=fopen("text.dat","w+"))==NULL)
	{
		perror("failed to fopen !\n");
		return -1;

	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs !\n");
		return -1;
	}
	printf("-------running in main!-------\n");
	printf("printf use line buffer");
	//while(1);
	exit(0);
	//_exit(0);
	//return 0;

}
