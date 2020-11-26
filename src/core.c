#include <stdio.h>
#include "core.h"
#include "feature.h"

int core(){
	int result = feature(7);
	printf("feature=%i\n", result);
	return 0;
}
