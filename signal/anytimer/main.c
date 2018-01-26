


void f1(void *p)
{
	printf("f1():%s\n",p);
}

void f2(void *p)
{
    printf("f2():%s\n",p);
}

int main()
{//BEGIN!END!..bbb...aaa..ccc...............
	puts("BEGIN!");

	job1 = at_addjob(5,f1,"aaa");
	if(job1 < 0)
	{
		fprintf(stderr,"at_addjob():%s\n",strerror(-job1));
		exit(1);
	}


	job2 = at_addjob(2,f2,"bbb");
	//job2 = at_addjob_repeat(2,f2,"bbb");
	/*if error*/

	at_addjob(7,f1,"ccc");
	/*if error*/

	puts("END!");


//	at_waitjob(job1);

//	at_canceljob(job2);		
//	at_waitjob(job2);

	while(1)
	{
		write(1,".",1);
		sleep(1);
	}

	exit(0);
}


