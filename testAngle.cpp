int testAngle()
{
  bool passed = true;
  Angle a1 = Angle(Angle::Degrees, 359);
  Angle a2 = Angle(Angle::Degrees, 2);
  Angle res = a1 + a2;
  double resd = res.get(Angle::Degrees);
  cout << "359deg + 2deg = " << resd << endl;
  if (passed) {
    passed = (fabs(resd - 1) < EPSILON);
  }

  Angle a3 = Angle(Angle::Degrees, 359);
  a3 += Angle(Angle::Degrees, 2);
  cout << "359deg += 2deg: " << a3.get(Angle::Degrees) << endl;
  if (passed) {
    passed = (fabs(a3.get(Angle::Degrees) - 1) < EPSILON);
  }

  cout << "359deg + 2deg to rad = " << res.get(Angle::Radians) << endl;
  if (passed) {
    passed = (fabs(res.get(Angle::Radians) - M_PI / 180) < EPSILON);
  }

  Angle a4 = Angle(Angle::Radians, 1.9*M_PI);
  Angle a5 = Angle(Angle::Radians, 0.2*M_PI);
  res = a4 + a5;
  double resr = res.get(Angle::Radians);
  cout << "1.9pi + 0.2pi = " << resr << endl;
  if (passed) {
    passed = (fabs(resr - 0.1*M_PI) < EPSILON);
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
