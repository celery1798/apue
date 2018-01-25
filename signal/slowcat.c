#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define BUFSIZE		CPS	
#define CPS			10

static volatile int loop = 1;

void alrm_handler(int s)
{
	alarm(1);
	loop = 0;
}

int main(int argc,char **argv)
{
	int sfd,dfd = 1;
	char buf[BUFSIZE];
	int len,ret,pos;
		
	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s <srcfile> <destfile>\n",argv[0]);
		exit(1);
	}


	signal(SIGALRM,alrm_handler);
	alarm(1);


	do
	{
		sfd = open(argv[1],O_RDONLY);
		if(sfd < 0)
		{
			if(errno != EINTR)
			{
				perror("open()");
				exit(1);
			}
		}
	}while(sfd < 0);

	
	while(1)
	{

		while(loop)
			pause();

		loop = 1;


		while((len = read(sfd,buf,BUFSIZE)) < 0)	
		{
			if(errno == EINTR)
				continue;
			perror("read()");
			break;
		}
		if(len == 0)
			break;
		

		pos = 0;
		while(len > 0)
		{
				ret = write(dfd,buf+pos,len);	
				if(ret < 0)
				{
					if(errno == EINTR)
						continue;
					perror("write()");
					break;
				}
				pos += ret;
				len -= ret;
		}	

	}

	close(sfd);

	exit(0);
}


