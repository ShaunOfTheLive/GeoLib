int testAngle()
{
  bool passed = true;
  double deg1 = 359.0;
  double deg2 = 2.0;
  double deg3 = 1.0;
  double rad1 = 1.9*M_PI;
  double rad2 = 0.2*M_PI;
  double rad3 = 0.1*M_PI;
  Angle a1 = Angle(Angle::Degrees, test1);
  Angle a2 = Angle(Angle::Degrees, test2);
  Angle res = a1 + a2;
  double resd = res.get(Angle::Degrees);
  cout << deg1 << " deg + " << deg1 << " deg = " << resd << endl;
  if (passed) {
    passed = (fabs(resd - (deg1 + deg2 - 360)) < EPSILON);
  }

  Angle a3 = Angle(Angle::Degrees, test1);
  a3 += Angle(Angle::Degrees, test2);
  cout << test1 << " deg += " << test2 << " deg: " << a3.get(Angle::Degrees) << endl;
  if (passed) {
    passed = (fabs(a3.get(Angle::Degrees) - (deg1 + deg2 - 360)) < EPSILON);
  }

  cout  << test1 << " deg + " << test2 << " deg to rad = " << res.get(Angle::Radians) << endl;
  if (passed) {
    passed = (fabs(res.get(Angle::Radians) - M_PI / 180) < EPSILON);
  }

  Angle a4 = Angle(Angle::Radians, test3);
  Angle a5 = Angle(Angle::Radians, test4);
  res = a4 + a5;
  double resr = res.get(Angle::Radians);
  cout << "1.9pi + 0.2pi = " << resr << endl;
  if (passed) {
    passed = (fabs(resr - test4) < EPSILON);
  }

  Angle a6 = Angle(Angle::Radians, 1.9*M_PI);
  a6 += Angle(Angle::Radians, 0.2*M_PI);
  cout << "1.9pi += 0.2pi: " << a6.get(Angle::Radians) << endl;
  if (passed) {
    passed = (fabs(a6.get(Angle::Radians) - 0.1*M_PI) < EPSILON);
  }

  cout << "1.9pi + 0.2pi to deg = " << res.get(Angle::Degrees) << endl;
  if (passed) {
    passed = (fabs(res.get(Angle::Degrees) - 0.1 * 180) < EPSILON);
  }


  if (passed) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
//  return TEST_UNDEFINED;
}
