#ifndef PROTO_H__
#define PROTO_H__

#define PATHSIZE		1024
#define DATASIZE		1024

enum
{
	MSG_PATH=1,
	MSG_DATA,
	MSG_ERR,
	MSG_EOT
};

struct msg_path_st
{
	long mtype;					/*must be MSG_PATH*/
	char path[PATHSIZE];		/*带尾0的串*/
};

struct msg_data_st
{	
	long mtype;					/*must be MSG_DATA*/
	char data[DATASIZE];
	int datalen;
};

struct msg_err_st
{
	long mtype;					/*must be MSG_ERR*/
	int err_code;
};

struct msg_eot_st
{
	long mtype;					/*must be MSG_EOT*/
};



#endif



