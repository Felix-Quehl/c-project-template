#include "test.h"
#include "stdio.h"

#define TEST_COUNT 2

int main()
{
	int test_count = TEST_COUNT;
	int test_counter = 0;
	int passed = 0;
	int faulty_test = 0;
	double percentage = 0.0;
	struct TestResult (*tests[TEST_COUNT])();

	tests[0] = feature_test;
	tests[1] = core_test;

	printf("============================\n");
	printf("TEST EXECUTION LOG\n");
	printf("----------------------------\n");

	for (test_counter = 0; test_counter < test_count; test_counter++)
	{
		struct TestResult (*test)() = tests[test_counter];
		struct TestResult result;
		printf("TEST %i\n", test_counter);
		result = test();
		if (!result.status)
			passed++;
		printf("\t%s Result: %s\n", result.name, result.info);
		printf("----------------------------\n");
	}
	percentage = passed * 100 / test_count;
	printf("TEST RESULT:\t%.2f %% (%i/%i) passed\n", percentage, passed, test_count);
	printf("============================\n");

	faulty_test = passed != test_count;
	return faulty_test;
}
