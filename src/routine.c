#include <stdio.h>
#include "routine.h"
#include "feature.h"
#include "logging.h"

int routine(void)
{
	
	int value;
	char buffer[100];

	value = feature(7);
	sprintf(buffer, "feature = %i", value);
	
	LOG_DEBUG(buffer);
	LOG_INFO(buffer);
	LOG_WARNING(buffer);
	LOG_ERROR(buffer);
	LOG_FATAL(buffer);

	return 0;

}
