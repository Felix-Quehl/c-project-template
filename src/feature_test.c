#include <stdio.h>
#include "feature.h"
#include "test.h"

struct TestResult feature_test()
{
	struct TestResult result = {0, "Feature Test", "passed"};

	if (feature(7) != 14)
	{
		result.status = 1;
		result.info = "failed, result for input 7 is not 14";
		return result;
	}

	if (feature(0) != 0)
	{
		result.status = 1;
		result.info = "failed, result for input 0 is not 0";
		return result;
	}

	if (feature(-1) != -2)
	{
		result.status = 1;
		result.info = "failed, result for input -1 is not -2";
		return result;
	}

	return result;
}
