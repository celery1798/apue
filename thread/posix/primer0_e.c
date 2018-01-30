#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define LEFT	30000000
#define RIGHT	30000200
#define THRNUM	(RIGHT-LEFT+1)

struct thr_arg_st
{
	int num;
};

void *thr_primer(void *p)
{
	int i,j,mark;

	i = ((struct thr_arg_st *)p)->num;

//	free(p);

	mark = 1;
	for(j = 2; j < i/2 ; j++)
	{
		if(i % j == 0)
		{
			mark = 0;
			break;
		}
	}

	if(mark)
		printf("%d is a primer.\n",i);

	pthread_exit(p);
}
int main()
{
	int i,err;
	pthread_t tid[THRNUM];
	struct thr_arg_st *ptr;


	for(i = LEFT; i <= RIGHT; i++)
	{
		ptr = malloc(sizeof(*ptr));
		/*if error*/
		ptr->num = i;

		err = pthread_create(tid+(i-LEFT),NULL,thr_primer,ptr);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}
	
	}
	
	void *ret;
	for(i = LEFT; i <= RIGHT; i++)
	{
		pthread_join(tid[i-LEFT],&ret);
		free(ret);
	}
	exit(0);

}



