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
