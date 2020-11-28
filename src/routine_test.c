#include <stdio.h>
#include "routine.h"
#include "test.h"

int routine_test()
{
	int errors;
	int temp;
	
	errors = 0;
	temp = routine();
	if (temp != 0)
	{
		printf("error: non zero return value %i\n", temp);
		errors++;
	}

	return errors;
}
