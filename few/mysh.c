#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <glob.h>
#include <string.h>

struct arg_st
{
	glob_t globres;
//	int flag1;
//	int fd[]
//	...
};

void prompt(void)
{
	printf("mysh-0.1:$ ");
}

void parse(char *line,struct arg_st *res)
{
//	"ls    -l /etc/  -a /tmp/out" 
//	"ls" "-l"  "/etc"
	char *tok;
	int i = 0;

	while(1)
	{
		tok = strsep(&line," \n\t");
		if(tok == NULL)
			break;
		if(tok[0] == '\0')
			continue;

		glob(tok,GLOB_NOCHECK|GLOB_APPEND*i,NULL,&res->globres);
		i = 1;
	}
}

int main()
{
	pid_t pid;
	char *line = NULL;
	size_t linesize = 0;
	struct arg_st cmd;

	while(1)
	{
		prompt();

		if(getline(&line,&linesize,stdin) < 0)
			break;

		// line -> "ls -l /etc/  -a /tmp/out"

		parse(line,&cmd);
		

		if(0  /*内部命令*/)
		{

		}
		else		//外部命令
		{
			pid = fork();
			if(pid < 0)
			{
				perror("fork()");
				exit(1);
			}
			if(pid == 0)	// child
			{
				execvp(cmd.globres.gl_pathv[0],cmd.globres.gl_pathv);
				perror("execvp()");
				exit(1);
			}
			else
				wait(NULL);

		}
	}

	exit(0);
}


