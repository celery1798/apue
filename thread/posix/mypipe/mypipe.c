

struct mypipe_st
{
	char data[PIPESIZE];
	int head,tail;
	int datalen;
	pthread_mutex_t mut;
	pthread_cond_t cond;	
};




