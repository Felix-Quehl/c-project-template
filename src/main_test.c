#include "test.h"
#include "stdio.h"

/* add new tests to this array definition */
#define __TESTS__ \
{ \
	feature_test, \
	routine_test \
}

void print_welcome(int count)
{
	printf("============================\n");
	printf("RUNNING %i TESTS\n", count);
	printf("============================\n");
}

int execute_test(struct TestResult (*test)())
{
	struct TestResult result;
	printf("----------------------------\n");
	result = test();
	printf("\t%s Result: %s\n", result.name, result.info);
	printf("----------------------------\n");
	return result.status;
}

void print_result(int passed, int count)
{
	double percentage;
	printf("============================\n");
	percentage = passed * 100 / count;
	printf("TEST SUMMERY: %.2f %% (%i/%i) passed\n", percentage, passed, count);
	printf("============================\n");
}

int main()
{

	struct TestResult (*tests[])() = __TESTS__;
	int count;
	int index;
	int passed;
	int failed;

	count = sizeof(tests)/sizeof(void*);
	passed = 0;

	print_welcome(count);
	
	for (index = 0; index < count; index++)
		passed += !execute_test(tests[index]);

	print_result(passed, count);

	failed = passed != count;

	return failed;

}
