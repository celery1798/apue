#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#include "proto.h"

int main(int argc,char **argv)
{
    int sd,size;
    struct sockaddr_in raddr;
    struct msg_st *sbuf;

	if(argc < 3)
	{
		fprintf(stderr,"Usage....\n");
		exit(1);
	}

	if(strlen(argv[2]) > NAMEMAX)
	{
		fprintf(stderr,"Name is too long.");
		exit(1);
	}

	size = sizeof(struct msg_st) + strlen(argv[2]);

	sbuf = malloc(size);
	/*if error*/	
	
    sd = socket(AF_INET,SOCK_DGRAM,0 /*IPPROTO_UDP*/);
    if(sd < 0)
    {
        perror("socket()");
        exit(1);
    }

	strcpy(sbuf->name,argv[2]);
	sbuf->math = htonl(rand()%100);
	sbuf->chinese = htonl(rand()%100);

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET,argv[1],&raddr.sin_addr);

	if(sendto(sd,sbuf,size,0,(void *)&raddr,sizeof(raddr)) < 0)
	{
		perror("sendto()");
		exit(1);
	}

	puts("ok!");

	free(sbuf);

	close(sd);

	exit(0);

}

