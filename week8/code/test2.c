#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>

int main()

{

    void *curr_brk, *tmp_brk = NULL;

    printf("Welcome to sbrk example:%d\n", getpid());

    tmp_brk = curr_brk = sbrk(0);   

    printf("Program Break Location1:%p\n", curr_brk);

    getchar();

    brk(curr_brk+4096); 

    curr_brk = sbrk(0);

    printf("Program break Location2:%p\n", curr_brk);

    int* a = (int *)tmp_brk+32; 

    *a = 32;

    printf("%d\n", *a);

    getchar();

    brk(tmp_brk);   

    curr_brk = sbrk(0);

    printf("Program Break Location3:%p\n", curr_brk);

    getchar();

    printf("%d\n", *a); 

    return 0;

}

