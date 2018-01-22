#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <pwd.h>
#include <time.h>
#include <string.h>

#define STRSIZE		1024
#define FMTSIZE		1024

int main(int argc,char **argv)
{
	time_t stamp;
	struct tm *tm;
	char timestr[STRSIZE];
	char fmt[FMTSIZE] = {'\0'};
	int ch;
	FILE *fp = stdout;

	stamp = time(NULL);
	tm = localtime(&stamp);

	while(1)
	{
		ch = getopt(argc,argv,"-y:mdH:MS");
		if(ch < 0)
			break;

		switch(ch)
		{
			case 1:
				if(fp == stdout)
				{
					fp = fopen(argv[optind-1],"w");				
					if(fp == NULL)
					{
						perror("fopen()");
						fp = stdout;
					}
				}
				break;	

			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmt,"%y ",FMTSIZE);
				else if(strcmp(optarg,"4") == 0)
						strncat(fmt,"%Y ",FMTSIZE);
				else
					fprintf(stderr,"Invalid argument of -y.\n");	

				break;

			case 'm':
				strncat(fmt,"%m ",FMTSIZE);
				break;

			case 'd':
				strncat(fmt,"%d ",FMTSIZE);
				break;

			case 'H':
				if(strcmp(optarg,"12") == 0)
                    strncat(fmt,"%I(%P) ",FMTSIZE);
                else if(strcmp(optarg,"24") == 0)
                        strncat(fmt,"%H ",FMTSIZE);
                else
                    fprintf(stderr,"Invalid argument of -H.\n");
				break;

			case 'M':
				strncat(fmt,"%M ",FMTSIZE);
				break;

			case 'S':
				strncat(fmt,"%S ",FMTSIZE);
				break;

			default:
				break;

		}

	}

	strncat(fmt,"\n",FMTSIZE);
	strftime(timestr,STRSIZE,fmt,tm);
	fputs(timestr,fp);

	if(fp != stdout)
		fclose(fp);

	exit(0);
}





