#include <stdio.h>
#include "core.h"
#include "test.h"

struct TestResult core_test()
{
	struct TestResult result = {0, "Core Test", "success"};

	if (core() != 0)
	{
		result.status = 1;
		result.info = "non zero return value";
		return result;
	}

	return result;
}
