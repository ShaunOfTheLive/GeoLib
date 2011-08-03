#include <iostream>
#include <string>
#include <unit++/unit++.h>
#include "CAngle.h"
#include "math.h"

using namespace std;
using namespace unitpp;

namespace {
  class CAngleTest: public suite
  {
    double deg1, deg2, rad1, rad2;
    Angle adeg1, adeg2, arad1, arad2;

    void test_operator_plus()
    {
      Angle adegadd = adeg1 + adeg2;
      Angle aradadd = arad1 + arad2;

      assert_true("operator+ with degrees", feq(adegadd.get(Angle::Degrees), deg1 + deg2 - 360));
      assert_true("operator+ with radians", feq(aradadd.get(Angle::Radians), rad1 + rad2 - 2*M_PI));
    }
    void test_operator_plus_eq()
    {
      Angle adegaddeq = adeg2;
      adegaddeq += adeg1;
      Angle aradaddeq = arad2;
      aradaddeq += arad1;

      assert_true("operator+= with degrees", feq(adegaddeq.get(Angle::Degrees), deg1 + deg2 - 360));
      assert_true("operator+= with radians", feq(aradaddeq.get(Angle::Radians), rad1 + rad2 - 2*M_PI));
    }
  public:
    CAngleTest() : suite("CAngle tests"),
    deg1(359.0), deg2(2.0), rad1(1.9*M_PI), rad2(0.2*M_PI),
    adeg1(Angle::Degrees, deg1), adeg2(Angle::Degrees, deg2), arad1(Angle::Radians, rad1), arad2(Angle::Radians, rad2)
    {
      add("test_operator_plus", testcase(this, "Test operator+", &CAngleTest::test_operator_plus));
      add("test_operator_plus_eq", testcase(this, "Test operator+=", &CAngleTest::test_operator_plus_eq));
      suite::main().add("CAngleTestSuite", this);
    }
  };
  CAngleTest* CAngleTestSuite = new CAngleTest();
}
