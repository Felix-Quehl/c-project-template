#include <stdio.h>
#include "routine.h"
#include "feature.h"

int routine(){
	int result = feature(7);
	printf("feature=%i\n", result);
	return 0;
}
