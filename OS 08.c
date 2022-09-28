#include <stdio.h>
#include <pthread.h>
void *threadFunc(void *arg)
{
	char *str;
	int i = 0;

	str=(char*)arg;

	while(i < 10 )
	{
		usleep(1);
		printf("threadFunc says: %s\n",str);
		++i;
	}

	return NULL;
}

int main(void)
{
	pthread_t pth;	
	int i = 0;

	pthread_create(&pth,NULL,threadFunc,"processing...");

	pthread_join(pth, NULL /* void ** return value could go here */);

	while(i < 10 )
	{
		usleep(1);
		printf("main() is running...\n");
		++i;
	}

	return 0;
}

