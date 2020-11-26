#ifndef TEST_HEADER
#define TEST_HEADER

/*logging functions*/
extern int log_test_pass(char *name);
extern int log_test_fail(char *name, char *info);

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
extern int log_summery(char *title, int run, int failed);

#endif
