#include "test.h"
#include "stdio.h"

#define TEST_COUNT 2

int log_test_pass(char *name)
{
	return printf("TEST %s passes\n", name);
}

int log_test_fail(char *name, char *info)
{
	return printf("TEST %s failed: %s\n", name, info);
}

int log_summery(char *title, int run, int failed)
{
	int r = 0;

	return r;
}

int main()
{
	int test_counter = 0;
	int failed_test_count = 0;
	double percentage = 0.0;
	struct TestResult (*tests[TEST_COUNT])();

	tests[0] = feature_test;
	tests[1] = core_test;

	printf("============================\n");

	for (test_counter = 0; test_counter < TEST_COUNT; test_counter++)
	{
		struct TestResult (*test)() = tests[test_counter];
		struct TestResult result = test();
		if (result.status)
		{
			log_test_fail(result.name, result.info);
			failed_test_count++;
		}
		else
		{
			log_test_pass(result.name);
		}
		printf("----------------------------\n");
	}
	percentage = (test_counter - failed_test_count) * 100 / test_counter;
	log_summery("App", TEST_COUNT, failed_test_count);
	printf("Failed:\t%i/%i\n", failed_test_count, test_counter);
	printf("Passed:\t%.2f %%\n", percentage);
	printf("============================\n");
	return failed_test_count;
}
