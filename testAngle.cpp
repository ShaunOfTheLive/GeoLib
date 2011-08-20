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
    double deg1, deg2, deg3;
    double rad1, rad2, rad3;
    Angle adeg1, adeg2, arad1, arad2;

    void test_constructors()
    {
      Angle atestdeg(Angle::Degrees, deg1);
      Angle atestrad(Angle::Radians, rad1);

      assert_true("construct angle with degrees", feq(atestdeg.get(), deg1));
      assert_true("construct angle with radians", feq(atestrad.get(), rad1));
    }
    void test_getset()
    {
      Angle atestdeg(Angle::Degrees, deg1);
      Angle atestrad(Angle::Radians, rad1);
      atestdeg.set(deg3);
      atestrad.set(rad3);

      assert_true("set and get with degrees", feq(atestdeg.get(), deg3));
      assert_true("set and get with radians", feq(atestrad.get(), rad3));
    }
    void test_getset_units()
    {
      Angle atestdeg(Angle::Degrees, deg1);
      Angle atestrad(Angle::Radians, rad1);
      atestdeg.set(Angle::Degrees, deg3);
      atestrad.set(Angle::Radians, rad3);

      assert_true("set and get with degrees", feq(atestdeg.get(Angle::Degrees), deg3));
      assert_true("set and get with radians", feq(atestrad.get(Angle::Radians), rad3));
    }
    void test_getset_convert()
    {
      Angle atestdeg(Angle::Degrees, deg1);
      Angle atestrad(Angle::Radians, rad1);

      atestdeg.set(Angle::Degrees, deg3);
      atestrad.set(Angle::Radians, rad3);

      assert_true("set with degrees and get with radians", feq(atestdeg.get(Angle::Radians), deg3 * M_PI / 180));
      assert_true("set with radians and get with degrees", feq(atestrad.get(Angle::Degrees), rad3 * 180 / M_PI));

      atestdeg.set(Angle::Radians, rad3);
      atestrad.set(Angle::Degrees, deg3);

      assert_true("set with radians and get with degrees", feq(atestdeg.get(Angle::Degrees), rad3 * 180 / M_PI));
      assert_true("set with degrees and get with radians", feq(atestrad.get(Angle::Radians), deg3 * M_PI / 180));
    }
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
    void test_range_rollover()
    {
      Angle rdeg = adeg1;
      Angle rrad = arad1;
      rdeg.setRange(5, 250);
      rrad.setRange(0.3*M_PI, 0.6*M_PI);

      rdeg.set(4);

      cout << "angle = " << rdeg.get() << endl;
      assert_true("degrees range >=5; setting 4", feq(rdeg.get(), 249));
    }
    void test_negation()
    {
      Angle ndeg = -adeg1;
      cout << "ndeg = " << ndeg.get() << endl;
      assert_true("negation", feq(ndeg.get(), 1));
    }
  public:
    CAngleTest() : suite("CAngle tests"),
    deg1(359.0), deg2(2.0), deg3(50.0),
    rad1(1.9*M_PI), rad2(0.2*M_PI), rad3(0.5*M_PI),
    adeg1(Angle::Degrees, deg1), adeg2(Angle::Degrees, deg2), arad1(Angle::Radians, rad1), arad2(Angle::Radians, rad2)
    {
      add("test_constructors", testcase(this, "Test constructors", &CAngleTest::test_constructors));
      add("test_getset", testcase(this, "Test getters and setters", &CAngleTest::test_getset));
      add("test_getset_units", testcase(this, "Test getters and setters specifying native units", &CAngleTest::test_getset_units));
      add("test_getset_convert", testcase(this, "Test getters and setters converting from native units", &CAngleTest::test_getset_convert));
      add("test_operator_plus", testcase(this, "Test operator+", &CAngleTest::test_operator_plus));
      add("test_operator_plus_eq", testcase(this, "Test operator+=", &CAngleTest::test_operator_plus_eq));
      add("test_range_rollover", testcase(this, "Test range rollover", &CAngleTest::test_range_rollover));
      add("test_negation", testcase(this, "Test negation", &CAngleTest::test_negation));
      suite::main().add("CAngleTestSuite", this);
    }
  };
  CAngleTest* CAngleTestSuite = new CAngleTest();
}
