#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>   
#include <sys/socket.h>
#include <unistd.h>

#include "proto.h"

#define STRSIZE		1024

int main()
{
	int sd,size;
	struct sockaddr_in laddr,raddr;
	socklen_t raddr_len;
	struct msg_st *rbuf;	
	char ipstr[STRSIZE];

	size = MSGMAX;
	rbuf = malloc(size);
	/*if error*/

	sd = socket(AF_INET,SOCK_DGRAM,0 /*IPPROTO_UDP*/);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}

	laddr.sin_family = AF_INET;
	laddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET,"0.0.0.0",&laddr.sin_addr);
	if(bind(sd,(void *)&laddr,sizeof(laddr)) < 0)
	{
		perror("bind()");
		exit(1);
	}

	raddr_len = sizeof(raddr);

	while(1)
	{
		if(recvfrom(sd,rbuf,size,0,(void *)&raddr,&raddr_len) < 0)
		{
			perror("recvfrom()");
			exit(1);
		}
	
		inet_ntop(AF_INET,&raddr.sin_addr,ipstr,STRSIZE);		

		printf("----MESSAGES FROM:%s:%d----\n",ipstr,ntohs(raddr.sin_port));
		printf("NAME = %s\n",rbuf->name);
		printf("MATH = %d\n",ntohl(rbuf->math));
		printf("CHINESE = %d\n",ntohl(rbuf->chinese));
	}

	free(rbuf);

	close(sd);

	exit(0);
}


