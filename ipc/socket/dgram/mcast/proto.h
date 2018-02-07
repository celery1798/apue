#ifndef PROTO_H__
#define PROTO_H__

#define NAMESIZE	11

#define MGROUP		"224.2.2.2"
#define RCVPORT		"1989"

struct msg_st
{
	uint8_t name[NAMESIZE];
	uint32_t math;
	uint32_t chinese;
}__attribute__((packed));



#endif

