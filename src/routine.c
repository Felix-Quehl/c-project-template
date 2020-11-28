#include <stdio.h>
#include "routine.h"
#include "feature.h"
#include "logging.h"

int routine(){
	int result = feature(7);
	LOG("INFO", "feature=%i\n", result);
	return 0;
}
