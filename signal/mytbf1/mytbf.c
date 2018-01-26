#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#include "mytbf.h"


struct mytbf_st
{
	int cps;
	int burst;
	int token;
	int pos;
};


static struct mytbf_st *job[MYTBF_MAX];
static int inited = 1;
static struct sigaction osa;

static void alrm_sa(int s,siginfo_t *infop, void *unused)
{
	int i;

	if(infop->si_code != SI_KERNEL)
		return ;

	for(i = 0 ; i < MYTBF_MAX; i++)
	{
		if(job[i] != NULL)
		{
			job[i]->token += job[i]->cps;
			if(job[i]->token > job[i]->burst)
				job[i]->token = job[i]->burst;
		}
	}
}

static void module_unload(void)
{
	int i;
	struct itimerval itv;

	itv.it_interval.tv_sec = 0;
    itv.it_interval.tv_usec = 0;
    itv.it_value.tv_sec = 0;
    itv.it_value.tv_usec = 0;
    if(setitimer(ITIMER_REAL,&itv,NULL) < 0)
    {
        perror("setitimer()");
        exit(1);
    }

	sigaction(SIGALRM,&osa,NULL);
	/*if error*/
	
	for(i = 0 ; i < MYTBF_MAX; i++)
		free(job[i]);
}

static void module_load(void)
{
	struct itimerval itv;
	struct sigaction sa;

	sa.sa_sigaction = alrm_sa;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if(sigaction(SIGALRM,&sa,&osa) < 0)
	{
		perror("sigaction()");
		exit(1);
	}
	
	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	if(setitimer(ITIMER_REAL,&itv,NULL) < 0)
	{
		perror("setitimer()");
		exit(1);
	}


	atexit(module_unload);

}

static int get_free_pos(void)
{
	int i;
	for(i = 0 ; i < MYTBF_MAX; i++)
		if(job[i] == NULL)
			return i;
	return -1;
}

mytbf_t *mytbf_init(int cps,int burst)
{
	struct mytbf_st *me;
	int pos;

	if(inited)
	{
		inited = 0;
		module_load();
	}

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;

	me->cps = cps;
	me->burst = burst;
	me->token = 0;

	pos = get_free_pos();
	if(pos < 0)
	{
		free(me);
		return NULL;
	}

	me->pos = pos;
	job[pos] = me;

	return me;
}

static int min(int a,int b)
{
	if(a < b)
		return a;
	return b;
}

int mytbf_fetchtoken(mytbf_t *ptr,int num)
{
	struct mytbf_st *me = ptr;
	int n;

	if(num <= 0)
		return -EINVAL;

	while(me->token <= 0)
		pause();

	n = min(me->token,num);

	me->token -= n ;
	
	return n;
}

int mytbf_returntoken(mytbf_t *ptr,int num)
{
	struct mytbf_st *me = ptr;

	if(num <= 0)
        return -1;

	me->token += num;
	if(me->token > me->burst)
		me->token = me->burst;
	
	return 0;
}


void mytbf_destroy(mytbf_t *ptr)
{
	struct mytbf_st *me = ptr;	
	
	job[me->pos] = NULL;
	
	free(me);

	return ;
}










