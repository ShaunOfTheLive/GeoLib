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
  for (int i = 0; i < TESTS_AMT; ++i) {
    autotest(i);
  }

  return 0;
}
