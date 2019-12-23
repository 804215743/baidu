#include "my.h"
pthread_mutex_t mutex;
int tickets=100;
sem_t empty,full;
void *worker0(void *arg)
{
	while(1)
	{
		sem_wait(&empty);
		if(tickets>0)
		{
			usleep(10000);
			printf("worker0 read ticket : %d\n",tickets--);
			tickets--;
			sem_post(&full);
		}
		else
		{
			sem_post(&full);
			break;

		}
	pthread_yield();
	}
	return NULL;
}

void *worker1(void *arg)
{
	sem_wait(&full);
	while(1)
	{
		if(tickets>0)
		{
			usleep(10000);
			printf("worker1 read ticket : %d\n",tickets);
			tickets--;
			sem_post(&empty);
		}
		else
		{
			sem_post(&empty);
			break;

		}
	pthread_yield();
	}
	return NULL;
}


int main()
{
	pthread_t tid[2];
	int i,ret;
	 void *(*pt[2])();
	pt[0]=worker0;
	pt[1]=worker1;
	ret=sem_init(&empty,0,1);
	ret=sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	for(i=0;i<2;i++)
	{
		ret=pthread_create(&tid[0],NULL,pt[i],NULL);
		if(ret!=0)
		{
			perror("create thread!\n");
			exit(1);
		}
	}	
	for(i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);
	}
	return 0;
}


