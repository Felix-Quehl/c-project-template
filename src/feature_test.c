#include <stdio.h>
#include "feature.h"
#include "test.h"

int feature_test(void)
{
	int errors;
	int temp;

	errors = 0;
	
	temp = feature(7);
	if (temp != 14)
	{
		printf("errors: result for 7 should be 14 and not %i\n", temp);
		errors++;
	}

	temp = feature(0);
	if (temp != 0)
	{
		printf("errors: result for 0 should be 0 and not %i\n", temp);
		errors++;
	}

	temp = feature(-1);
	if (temp != -2)
	{
		printf("errors: result for -1 should be -2 and not %i\n", temp);
		errors++;
	}

	return errors;
}
