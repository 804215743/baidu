#include <stdio.h>
#include "dylib.h"

int main()
{
	int a[10];
	init(a,10);
	show(a,10);
	printf("max = %4d\n",max(a,10));
	printf("sum = %4d\n",sum(a,10));
	return 0;


}
