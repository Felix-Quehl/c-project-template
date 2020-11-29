#include "logging.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void _log(char* file, int line, char* level, char* message)
{
	time_t now;
	char buffer[sizeof "yyyy-mm-ddThh:mm:ssZ"];
	time(&now);
	strftime(buffer, sizeof buffer, "%FT%TZ", gmtime(&now));
   	printf("%s\t%s:%i\t%s\t%s\n",buffer, file, line, level, message);
}
