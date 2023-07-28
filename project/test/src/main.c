#include <stdio.h>
#include <assert.h>
#include "myfunction.h"

void test_one()
{
	int expected = 10;

	int a = 3;
	int b = 7;
	int actual = myfunction(a,b);
	assert(expected == actual);

}

int main(int argc, char* args[])
{
	test_one();
	printf("all test passed\n");
	return 0;
}
