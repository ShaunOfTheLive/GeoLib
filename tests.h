#define TEST_ANGLE 1
#define TEST_LINESEGMENT1 2
#define TEST_LINESEGMENT2 4
#define TEST_PRINT 8
#define TEST_ALL 1023
#define TESTS_AMT 4

#define TESTS (TEST_ALL & ~TEST_LINESEGMENT1)

#define TEST_FAILED 0
#define TEST_PASSED 1
#define TEST_INACTIVE 2
#define TEST_UNDEFINED 3

char** res_strings = {"TEST_FAILED", "TEST_PASSED", "TEST_INACTIVE", "TEST_UNDEFINED"};

void tresult(int ret) {
}

typedef int (*testFunc)();

testFunc tests[TESTS_AMT] = {NULL};

int nullFunc() {}
testFunc nullFuncp = &nullFunc;
int i = 0;

#if (TESTS & TEST_ANGLE)
  #include "testAngle.cpp"
  tests[i] = &testAngle;
#else
  tests[i] = nullFuncp;
#endif
i++;

#if (TESTS & TEST_LINESEGMENT1)
  #include "testLineSegment1.cpp"
  tests[i] = &testLineSegment1;
#else
  tests[i] = nullFuncp;
#endif
i++;

#if (TESTS & TEST_LINESEGMENT2)
  #include "testLineSegment2.cpp"
  tests[i] = &testLineSegment2;
#else
  tests[i] = nullFuncp;
#endif
i++;

#if (TESTS & TEST_PRINT)
  #include "testPrint.cpp"
  tests[i] = &testPrint;
#else
  tests[i] = nullFuncp;
#endif
i++;
