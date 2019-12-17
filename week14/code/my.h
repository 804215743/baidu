#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <pthread.h>
#define NUM 4
#define LOOP 1000000
struct sendval{
	int n;
	int s;
};
