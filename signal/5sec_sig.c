#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdint.h>

static volatile int loop = 1;

void alrm_handler(int s)
{
	loop = 0;	
}

int main()
{
	int64_t count = 0;

	signal(SIGALRM,alrm_handler);
	alarm(5);

	while(loop)
		count++;

	printf("%lld\n",(long long)count);	


	exit(0);
}


