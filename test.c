#include "ch2.h"
int main()
{
	int i;
	printf("----calling program----\n");
	sleep(3);
	i=system("./test");
	printf("----calling end----\n");
	printf("return value=%d\n",i);
	return 0;

}
