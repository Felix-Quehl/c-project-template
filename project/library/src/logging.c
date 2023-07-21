#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void _log(char* file, int line, char* level, char* message)
{
	time_t now;
	char buffer[64];
	time(&now);
	strftime(buffer, sizeof buffer, DATETIME_FORMAT, gmtime(&now));
   	printf("%s\t%s:%i\t%s\t%s\n",buffer, file, line, level, message);
}
