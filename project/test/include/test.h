#ifndef TEST_HEADER
#define TEST_HEADER

struct TestInfo
{
    int (*function)(void);
    char *name;
};

void feature_test(void);
void routine_test(void);

#endif
