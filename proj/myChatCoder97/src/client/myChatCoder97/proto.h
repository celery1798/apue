#ifndef PROTOCAL_H
#define PROTOCAL_H

//#pragma pack(1)

#define DEFAULT_SERVER_IP           "192.168.100.84"
#define DEFAULT_SERVER_PORT			1989

#define SIZE                        128

//<==================login================>
#define DENGLU_STATUS_OK             0
#define DENGLU_STATUS_ERROR          1
//#define DENGLU_SERVER_IP             DEFAULT_SERVER_IP
#define DENGLU_SERVER_PORT           1235

struct denglu_st 
{
    char uname[SIZE];
    char password[SIZE];
    uint32_t status;
}__attribute__((packed));

#endif // PROTOCAL_H
