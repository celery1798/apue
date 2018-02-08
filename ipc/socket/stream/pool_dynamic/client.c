#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#include "proto.h"

int main(int argc,char **argv)
{
	int sd;
	struct sockaddr_in raddr;
	FILE *fp;
	long long stamp;

	if(argc < 2)
	{
		fprintf(stderr,"Usage....\n");
		exit(1);
	}

	sd = socket(AF_INET,SOCK_STREAM,0/*IPPROTO_TCP,IPPROTO_SCTP*/);
    if(sd < 0)
    {
        perror("socket()");
        exit(1);
    }

	raddr.sin_family = AF_INET;
	inet_pton(AF_INET,argv[1],&raddr.sin_addr);
	raddr.sin_port = htons(atoi(SERVERPORT));
	if(connect(sd,(void *)&raddr,sizeof(raddr)) < 0)
	{
		perror("connect()");
		exit(1);
	}

	fp = fdopen(sd,"r+");
	if(fp == NULL)
	{
		perror("fdopen()");
		exit(1);
	}

	if(fscanf(fp,FMT_STAMP,&stamp) < 1)
	{
		fprintf(stderr,"fscanf():Bad format.\n");
		exit(1);
	}
	else
		printf("stamp = %lld\n",stamp);

	fclose(fp);

	exit(0);
}






