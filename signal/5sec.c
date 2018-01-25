#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdint.h>

int main()
{
	int64_t count = 0;
	time_t end;

	end = time(NULL)+5;

	while(time(NULL) <= end)
		count++;

	printf("%lld\n",(long long)count);	


	exit(0);
}


