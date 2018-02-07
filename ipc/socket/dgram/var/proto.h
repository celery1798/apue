#ifndef PROTO_H__
#define PROTO_H__

#define MSGMAX		(512-8)
#define NAMEMAX		(MSGMAX-8)

#define RCVPORT		"1989"

struct msg_st
{
	uint32_t math;
	uint32_t chinese;
	uint8_t name[1];
}__attribute__((packed));



#endif

