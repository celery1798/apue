#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alrm_handler(int s)
{
	alarm(1);
	puts("ALRM.");
	return ;
}

int main()
{

	signal(SIGALRM,alrm_handler);
    alarm(1);


	while(1);


/*

	signal(SIGALRM,alrm_handler);
	alarm(3);

	pause();

	while(1)
	{
		printf("while(1)\n");
		sleep(1);
	}
*/
	exit(0);
}


