#ifndef PROTO_H__
#define PROTO_H__

#define PATHSIZE		1024
#define DATASIZE		1024

enum
{
	MSG_PATH=1,
	MSG_S2C
};

struct msg_path_st
{
	long mtype;					/*must be MSG_PATH*/
	char path[PATHSIZE];		/*带尾0的串*/
};

struct msg_s2c_st
{	
	long mtype;					/*must be MSG_S2C*/
	int datalen;
	/*
	datalen < 0  :  -errno
			= 0	 :  eot
			> 0  :  data

*/
	char data[DATASIZE];
};


#endif

