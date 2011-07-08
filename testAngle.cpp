int testAngle()
{
  bool passed = true;
  Angle a1 = Angle::degrees(359);
  Angle a2 = Angle::degrees(2);
  Angle res = a1 + a2;
  double resd = res.getDegrees();
  cout << "359deg + 2deg = " << resd << endl;
  if (passed) {
    passed = (fabs(resd - 1) < EPSILON);
  }

  Angle a3 = Angle::degrees(359);
  a3 += Angle::degrees(2);
  cout << "359deg += 2deg: " << a3.getDegrees() << endl;
  if (passed) {
    passed = (fabs(a3.getDegrees() - 1) < EPSILON);
  }

  cout << "359deg + 2deg to rad = " << res.getRadians() << endl;
  if (passed) {
    passed = (fabs(res.getRadians() - M_PI / 180) < EPSILON);
  }

  Angle a4 = Angle::radians(1.9*M_PI);
  Angle a5 = Angle::radians(0.2*M_PI);
  res = a4 + a5;
  double resr = res.getRadians();
  cout << "1.9pi + 0.2pi = " << resr << endl;
  if (passed) {
    passed = (fabs(resr - 0.1*M_PI) < EPSILON);
  }

  Angle a6 = Angle::radians(1.9*M_PI);
  a6 += Angle::radians(0.2*M_PI);
  cout << "1.9pi += 0.2pi: " << a6.getRadians() << endl;
  if (passed) {
    passed = (fabs(a6.getRadians() - 0.1*M_PI) < EPSILON);
  }

  cout << "1.9pi + 0.2pi to deg = " << res.getDegrees() << endl;
  if (passed) {
    passed = (fabs(res.getDegrees() - 0.1 * 180) < EPSILON);
  }


  if (passed) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
//  return TEST_UNDEFINED;
}
