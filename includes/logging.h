#ifndef LOGGING_HEADER
#define LOGGING_HEADER

#include "stdio.h"
#include "time.h"

void print_time ( void )
{
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	printf(
			"%d.%d.%d %d:%d:%d\t",
			timeinfo->tm_year+1900,
			timeinfo->tm_mon+1,
			timeinfo->tm_mday,
			timeinfo->tm_hour,
			timeinfo->tm_min,
			timeinfo->tm_sec
	);
}


#define LOG(level, args...) print_time(); printf("%s:%d\t", __FILE__, __LINE__); printf("%s:\t", level); printf(args)

#endif
