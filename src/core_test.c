#include <stdio.h>
#include "core.h"
#include "test.h"

struct TestResult core_test()
{
	struct TestResult result = {0, "Core Test", "passed"};

	if (core() != 0)
	{
		result.status = 1;
		result.info = "failed, non zero return value";
		return result;
	}

	return result;
}
