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
char func_names[][20] = {"Angle addition test", "Line segment test 1", "Line segment test 2", "Print test"};

char res_strings[][20] = {"FAILED", "PASSED", "INACTIVE", "UNDEFINED"};

void tinit(int num) {
  cout << "* " << func_names[num] << ": " << endl;
}
void tresult(int ret) {
  cout << "* Result: ";
  cout << res_strings[ret] << endl;
  cout << "**********" << endl;
}

typedef int (*testFunc)();

int nullFunc() { return TEST_UNDEFINED; }
testFunc nullFuncp = &nullFunc;

#if (TESTS & TEST_ANGLE)
  #include "testAngle.cpp"
  testFunc ptestAngle = &testAngle;
#else
  testFunc ptestAngle = nullFuncp;
#endif

#if (TESTS & TEST_LINESEGMENT1)
  #include "testLineSegment1.cpp"
  testFunc ptestLineSegment1 = &testLineSegment1;
#else
  testFunc ptestLineSegment1 = nullFuncp;
#endif

#if (TESTS & TEST_LINESEGMENT2)
  #include "testLineSegment2.cpp"
  testFunc ptestLineSegment2 = &testLineSegment2;
#else
  testFunc ptestLineSegment2 = nullFuncp;
#endif

#if (TESTS & TEST_PRINT)
  #include "testPrint.cpp"
  testFunc ptestPrint = &testPrint;
#else
  testFunc ptestPrint = nullFuncp;
#endif

testFunc tests[] = {ptestAngle, ptestLineSegment1, ptestLineSegment2, ptestPrint};

void autotest(int num) {
  if (tests[num] != &nullFunc) {
    tinit(num);
    tresult((*tests[num])());
  }
}
