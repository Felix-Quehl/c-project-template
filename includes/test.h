#ifndef TEST_HEADER
#define TEST_HEADER

/*struct for result of test functions*/
struct TestResult
{
    int status;
    char *name;
    char *info;
};

/*test cases*/
extern struct TestResult feature_test();
extern struct TestResult core_test();

#endif
