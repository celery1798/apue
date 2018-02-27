#ifndef PROTOCAL_H
#define PROTOCAL_H

#define DEFAULT_SERVER_IP               "192.168.100.225"

//<==================register================>
#define UNAME_SIZE	                32
#define ZHUCE_STATUS_OK			    0
#define ZHUCE_STATUS_ERROR          1
#define ZHUCE_SERVER_IP             DEFAULT_SERVER_IP
#define ZHUCE_SERVER_PORT           1234

#define FEMALE                      0
#define MALE                        1

struct zhuce_st {
    char uname[UNAME_SIZE];
    char password[UNAME_SIZE];
    int sex;
    int status;
};
//zhuce table
//id(integer, uname text,  passwd text)

//<==================login================>
#define DENGLU_STATUS_OK             0
#define DENGLU_STATUS_ERROR          1
#define DENGLU_SERVER_IP             DEFAULT_SERVER_IP
#define DENGLU_SERVER_PORT           1235

struct denglu_st {
    char uname[UNAME_SIZE];
    char password[UNAME_SIZE];
    int status;
};

//<=================save address===========>
#define JIZHUDIZHI_SERVER_IP            DEFAULT_SERVER_IP
#define JIZHUDIZHI_SERVER_PORT          1236
#define JIZHUDIZHI_STATUS_OK            0
#define JIZHUDIZHI_STATUS_ERROR         1

struct jizhudizhi_st {
   char uname[UNAME_SIZE];
   int status;
};

//denglu table
//denglu(id integer, uname text, addr blob)

//<==================addFriend================>
#define TIANJIAHAOYOU_STATUS_OK         0
#define TIANJIAHAOYOU_STATUS_ERROR      1
#define TIANJIAHAOYOU_SERVER_IP         DEFAULT_SERVER_IP
#define TIANJIAHAOYOU_SERVER_PORT       1237
#define TIANJIAHAOYOU_STATUS_FRIEND     2
struct tianjiahaoyou_st {
    char src_uname[UNAME_SIZE];
    char uname[UNAME_SIZE];
    char name[UNAME_SIZE];//server write
    int status;
};

//hy_xxx table
//hy_xxx(id integer, uname text, name text)

//<==================talk================>
#define LIAOTIAN_STATUS_OK              0
#define LIAOTIAN_STATUS_ERROR           1
#define LIAOTIAN_SERVER_IP              DEFAULT_SERVER_IP
#define LIAOTIAN_SERVER_PORT            1238
#define MSG_UNAME_SIZE                  1024

#define LIAOTIAN_CLIENT_PORT            8888

#define HAOYOU_ITEM                     2

struct liaotian_st {
    char src_uname[UNAME_SIZE];
    char dst_uname[UNAME_SIZE];
    char time[UNAME_SIZE];
    char msg[MSG_UNAME_SIZE];
    int status;
};
#endif // PROTOCAL_H
