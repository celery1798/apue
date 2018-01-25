#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define BUFSIZE		1024	
#define CPS			10
#define BURST		1000

int main(int argc,char **argv)
{
	int sfd,dfd = 1;
	char buf[BUFSIZE];
	int len,ret,pos;
	mytbf_t *tbf;		

	if(argc < 2)
	{
		fprintf(stderr,"Usage: %s <srcfile> <destfile>\n",argv[0]);
		exit(1);
	}

	tbf = mytbf_init(CPS,BURST);
	if(    )
	{

	}

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

		size = mytbf_fetchtoken(tbf,BUFSIZE);
		if(		)
		{
		
		}


		while((len = read(sfd,buf,size)) < 0)	
		{
			if(errno == EINTR)
				continue;
			perror("read()");
			break;
		}
		if(len == 0)
			break;
		


		if(size-len > 0)
			mytbf_returntoken(tbf,size-len);



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

	mytbf_destroy(tbf);


	exit(0);
}


