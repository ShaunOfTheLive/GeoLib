int testAngle()
{
  Angle a1 = Angle::degrees(359);
  Angle a2 = Angle::degrees(2);
  if ((a1+a2).getDegrees() == 1) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
//  return TEST_UNDEFINED;
}
