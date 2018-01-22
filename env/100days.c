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

int main(int argc,char **argv)
{
	time_t stamp;
	struct tm *tm;
	char timestr[STRSIZE];

	stamp = time(NULL);
	tm = localtime(&stamp);
	strftime(timestr,STRSIZE,"Now:%Y-%m-%d",tm);
	puts(timestr);

	tm->tm_mday += 100;
	mktime(tm);
	strftime(timestr,STRSIZE,"100 days later:%Y-%m-%d",tm);
    puts(timestr);


	exit(0);
}





