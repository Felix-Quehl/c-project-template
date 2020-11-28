#include "test.h"
#include "stdio.h"


int main(void)
{

	int count;
	int index;
	int passed;
	int errors;
	double percentage;
	struct TestInfo test;
	struct TestInfo tests[] =
	{
		{feature_test, "Feature Test"},
		{routine_test, "Routine Test"}
	};


	count = sizeof(tests)/sizeof(struct TestInfo);
	passed = 0;

	printf("============================\n");
	printf("RUNNING %i TESTS\n", count);
	printf("============================\n");
	
	for (index = 0; index < count; index++)
	{
		test = tests[index];
		printf("----------------------------\n");
		printf("RUNNING %s\n", test.name);
		errors = test.function();
		if (errors == 0)
		{
			passed++;
			printf("PASSED %s\n", test.name);
		}
		else
		{
			printf("ERRORS %s: %i\n", test.name, errors);
		}
		printf("----------------------------\n");
	}

	printf("============================\n");
	percentage = passed * 100 / count;
	printf("TEST SUMMERY: %.2f %% (%i/%i) passed\n", percentage, passed, count);
	printf("============================\n");

	errors = passed != count;

	return errors;

}
