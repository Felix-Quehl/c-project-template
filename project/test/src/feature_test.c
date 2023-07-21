#include <stdio.h>
#include <assert.h>
#include "feature.h"
#include "test.h"

void feature_test(void)
{
	assert(feature(7) == 14);
	assert(feature(0) == 0);
	assert(feature(-1) == -2);
}
