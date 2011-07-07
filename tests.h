#define TEST_ANGLE 1
#define TEST_LINESEGMENT1 2
#define TEST_LINESEGMENT2 4
#define TEST_PRINT 8
#define TEST_ALL 1023

#define TESTS (TEST_ALL & ~TEST_LINESEGMENT1)

#if (TESTS & TEST_ANGLE)
  #include "testAngle.cpp"
#else
  void testAngle() {}
#endif

#if (TESTS & TEST_LINESEGMENT1)
  #include "testLineSegment1.cpp"
#else
  void testLineSegment1() {}
#endif

#if (TESTS & TEST_LINESEGMENT2)
  #include "testLineSegment2.cpp"
#else
  void testLineSegment2() {}
#endif

#if (TESTS & TEST_PRINT)
  #include "testPrint.cpp"
#else
  void testPrint() {}
#endif
