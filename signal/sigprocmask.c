#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
我们不能决定信号什么时候到来,但是可以决定信号什么时候被响应

保护一段代码不受某个/某些信号的干扰 

*/

void int_handler(int s)	
{
	write(1,"!",1);
}

int main()
{
	int i,j;
	sigset_t set,oset,saveset;

	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	signal(SIGINT,int_handler);
	
	sigprocmask(SIG_UNBLOCK,&set,&saveset);

	for(j = 0 ; j < 10000; j++)
	{
		sigprocmask(SIG_BLOCK,&set,NULL);
//		sigprocmask(SIG_BLOCK,&set,&oset);

		for(i = 0 ; i < 5; i++)
		{
			write(1,"*",1);
			sleep(1);
		}
		write(1,"\n",1);
		sigprocmask(SIG_UNBLOCK,&set,NULL);
//		sigprocmask(SIG_SETMASK,&oset,NULL);
	}

	sigprocmask(SIG_SETMASK,&saveset,NULL);	

	exit(0);
}


