#include <iostream>
#include <vector>
using namespace std;

#include "CPoint.h"
#include "CAngle.h"
#include "CLineSegment.h"
#include "CTriangle.h"

#include "tests.h"

int main()
{
  testAngle();
  testLineSegment1();
  testLineSegment2();
  testPrint();

  return 0;
}
