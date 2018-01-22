#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
不要凭空猜测或假设父子进程谁先被调度,取决于调度器的策略

*/

int main()
{
	pid_t pid;

	printf("[%d]Begin!",getpid());


	fflush(NULL);	/*!!!!*/
	
	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)	// child
	{
		printf("[%d]Child is working.\n",getpid());
	}
	else			// parent
	{
		printf("[%d]Parent is working.\n",getpid());
	}

	printf("[%d]End!\n",getpid());

//	sleep(10000);
	
	exit(0);
}


