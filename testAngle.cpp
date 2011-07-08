int testAngle()
{
  Angle a1 = Angle::degrees(359);
  Angle a2 = Angle::degrees(2);
  Angle res = a1+a2;
  double resd = res.getDegrees();
  cout << "359deg + 2deg = " << resd << endl;
  if (fabs(resd - 1) < EPSILON) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
//  return TEST_UNDEFINED;
}
