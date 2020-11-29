 ![PIPELINE](https://github.com/Felix-Quehl/c89-project-template/workflows/Continuous%20Integration/badge.svg?branch=main&event=push)![Code Analysis](https://github.com/Felix-Quehl/c-project-template/workflows/Code%20Analysis/badge.svg?branch=main&event=push)

# ISO9899:1990 (C89, C90, ANSI) Linux Project Example

This repository features a **example project** targeting linux for the **ISO9899:1990 (C89, C90, ANSI) language standard** with **build system**, **test execution**, **coverage report and check**, all in a **automated pipeline**.

## Why ISO9899:1990

* portability
* compatibility
* little syntactic sugar
* full control
* low level

## Why no Frameworks and only standard tooling?

Having external dependecies or foreign code can cause problems.
So writing everthing by yourself has advandages:

* Having no frameworks is a lean approche with low overhead
* Writing own tooling help to understand the projects needs
* Solving problems on your own increases the developers skills
* Not having foreign code means not having to rely on others
* Can be setup and compiled off-line
* reduced binary size because only whats needed is implemented
* fully compartible with your target platform
* no exotic dependecies

## How to Build

Everything is automated using `make` as a build system.
The project uses the `clang` compiler along with `llvm` as tooling for coder coverage.
Install needed packages via your package manage.

```bash
# install needed packages
sudo apt install make clang llvm
```

To build various targets just type `make` and the target name like `release`, `debug` or `test`.
It is recommented to clean build by adding `clean`.

```bash
# clean relase build
make clean release

# clean debug build
make clean debug

# clean debug build
make clean debug
```

To executed the test you should build a `clean` `test` version and execute it with `check`.
To check how many code is coverd by your test execute the `coverage` recipie.

```bash
# performs a clean test build,
# executes the tests and
# makes a code coverage terminal-prompt and check.
make clean test check coverage
```

## Project Details

Some files are just for gitlab and have nothing to do with the actual C code.
The important files are:

```bash
.
├── Makefile
├── includes
│   ├── feature.h
│   ├── routine.h
│   └── test.h
└── src
    ├── feature.c
    ├── feature_test.c
    ├── main.c
    ├── main.o
    ├── main_test.c
    ├── routine.c
    └── routine_test.c
```

### Buildsystem (./Makefile)

```bash
.
└── Makefile
```

The project uses `make` to script building and testing your code.
Here is the [Documentation](https://www.gnu.org/software/make/manual/make.html#Reading).

Here are what you can do:

* clean the project from build overlefts with `make clean`
* compile and link release executable `make release`
* compile and link a debugging executable  `make debug`
* compile and link a test executable `make test`
* runs the test executable `make check`
* collect and checks the test/code coverage of the test executable `make coverage`

You also can chain commands for example:

* to clean build a release version with `make clean release`
* run the hole quality gate chain with `make clean test check coverage`

Make can also process things in parallel with using the `-j <number of threads>` paramter which is only recommended for:

* make release
* make debug
* make release

So for example you can do something like:

*$(nproc) returns how many concurrent thread executions the cpu offers.*

```bash
make clean 
make test -j $(nproc) 
make check coverage
```

### Header Files (./include/*.h)

```bash
.
└── includes
    ├── feature.h
    ├── routine.h
    └── test.h
```

A header file is a file containing C declarations and definitions to be shared between several source files. Header files are a kind of contract to keep track of what is implemented. As a intrinstic concept of C you should find a lot of information about header files on the internet, so i will not further explain them here. Here is a link to start [with the GNU Documentation](https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html#:~:text=A%20header%20file%20is%20a,preprocessing%20directive%20'%20%23include%20'.). When adding header files, just place them into the `./include/` directory so they are picked up by the build system automatically.

#### Test Functions (./include/test.h)

```bash
.
└── includes
    └── test.h
```

```c
#ifndef TEST_HEADER
#define TEST_HEADER

struct TestInfo
{
    int (*function)(void);
    char *name;
};

extern int feature_test(void);
extern int routine_test(void);

#endif
```

#### Test Functions

The project implemented vanilla C testing without a framework. 
When you plan to add tests define there signature in this header files.

To have a "drop-in" test that can be simply added a test function should take no paramter,
and return a `int` that represents the amount of assertion errors.
Test functions should have the follow signature:

```C
extern int your_test_name(void);
```

*There are some example test implemented which you can take a look at.*


```c
extern int feature_test(void);
extern int routine_test(void);
```

#### TestInfo Struct

The Struct is designed to hold a function pointer to a test function,
and a string to give a meaning full name within the logs.
It is used to add test in the execution collection in the `./src/main_test.c`.
For details look the the corresponding sections for the `main_test.c`.

```c
struct TestInfo
{
    int (*function)(void);
    char *name;
};
```

#### Other Headers

```bash
.
└── includes
    ├── feature.h
    └── routine.h
```

The other headerfiles are just example code to show case how business logic would be implemented and tests.


### Code Files (./src/*.c)


Code files implemented the actual functionality that was defined in the header files and provide the programs entry points.
There should be a lot of information about how to write C code files in the internet, so i will not give further general details here.

```bash
.
└── src
    ├── feature.c
    ├── feature_test.c
    ├── main.c
    ├── main_test.c
    ├── routine.c
    └── routine_test.c
```

#### Entry Points (./src/main*.c)

```bash
.
└── src
    ├── main.c
    └── main_test.c
```

The `main.c` and `main_test.c` are the entry point of the executables where the `main.c` is the default entry point, and the `main_test.c` is the entry point for the test build executable.

You can fully modify the `main.c` to fit your business logic, but keep in mind that you can not really test your `main.c` code automated because C will always call the `main` function to start your software.

```c
#include "routine.h"

int main()
{
 return routine();
}
```

The where the `main_test.c` comes to play.
Here is a logic implemented takes care of running your tests and checking the result.
You will not really have to touch much here.

To add tests search for the `struct TestInfo tests[]` and add a entry at the end like `{my_test_function, "Cool Test"}`.
Make sure that you have defined your test function in the `./include/test.h` header file and actually implemented the test in a code file.
How to write test function is show casted later on.

```c
struct TestInfo tests[] =
	{
		{feature_test, "Feature Test"},
		{routine_test, "Routine Test"},
  {my_test_function, "Cool Test"}
	};
```

Here is the full code of the test execution.

```
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

```

#### Business Logic and Test Code Files (./src/*.c)

```bash
.
└── src
    ├── feature.c
    ├── feature_test.c
    ├── routine.c
    └── routine_test.c
```

Add new code files with business logic and test functions.
To have a high code coverage you should test all your business logic.
Lets take a look at a example.

###### Example

The so called "feature" code just adds a number to itself.

```c
#include "feature.h"

int feature(int a)
{
	return a + a;
}
````

The test function calls this business logic function with various values and makes sure the output is correct,
if not a info is printed and the error counter is incremented.
After all calls are done, the function returns how many errors have occurred.

Here is the code:

```c
  
#include <stdio.h>
#include "feature.h"
#include "test.h"

int feature_test(void)
{
	int errors;
	int temp;

	errors = 0;
	
	temp = feature(7);
	if (feature(7) != 14)
	{
		printf("errors: result for 7 should be 14 and not %i\n", temp);
		errors++;
	}

	temp = feature(0);
	if (temp != 0)
	{
		printf("errors: result for 0 should be 0 and not %i\n", temp);
		errors++;
	}

	temp = feature(-1);
	if (temp != -2)
	{
		printf("errors: result for -1 should be -2 and not %i\n", temp);
		errors++;
	}

	return errors;
}
```
