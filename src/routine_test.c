#include <stdio.h>
#include "routine.h"
#include "test.h"

struct TestResult routine_test()
{
	struct TestResult result = {0, "Routine Test", "passed"};

	if (routine() != 0)
	{
		result.status = 1;
		result.info = "failed, non zero return value";
		return result;
	}

	return result;
}
