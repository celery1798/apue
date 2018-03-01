



int main()
{

	


	fork();

	if ( == 0)
	{
		execl("./zhuce","zhuce",NULL);
		perror();
		exit(1);
	}

	fork();

	if( == 0)
	{
		execl("./denglu","zhuce",NULL);
        perror();
        exit(1);
	}

	while(1)
	{
		pid = wait(NULL);
		if(pid < 0)
			if(errno == ECHILD);
				exit(0);
	}



	exit(0);
}



