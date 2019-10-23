#include <stdio.h>
#include "/baidu/week6/code/staticlib/staticlib.h"

int main()
{
	int a[10];
	initarray(a,10);
	showarray(a,10);
	printf("max = %4d\n",max(a,10));
	printf("sum = %4d\n",sum(a,10));
	return 0;


}
