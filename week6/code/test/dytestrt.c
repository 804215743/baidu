#include <stdio.h>
#include "dylib.h"
#include <stdlib.h>
#include <dlfcn.h>
int main()
{
	void *hd;
	void (*f1)();
	void (*f2)();
	int (*f3)(),(*f4)();
	char *error;
	int a[10];
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}	
	f1=dlsym(hd,"init");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(hd,"show");
	if((error=dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(hd,"max");
	if((error=dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f4=dlsym(hd,"sum");
	if((error=dlerror()) != NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1(a,10);
	f2(a,10);
	printf("max = %4d\n",f3(a,10));
	printf("sum = %4d\n",f4(a,10));
	if(dlclose(hd)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}	
	return 0;


}
