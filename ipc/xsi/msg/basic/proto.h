#ifndef PROTO_H__
#define PROTO_H__

#define NAMESIZE	32

#define MSGTYPE		6

#define KEYPATH		"/etc/services"
#define KEYPROJ		'x'

struct msg_st
{
	long mtype;
	char name[NAMESIZE];
	int math;
	int chinese;
};



#endif

