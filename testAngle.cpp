int testAngle()
{
  bool passed = true;
  double deg1 = 359.0;
  double deg2 = 2.0;
  double rad1 = 1.9*M_PI;
  double rad2 = 0.2*M_PI;
  Angle a1 = Angle(Angle::Degrees, deg1);
  Angle a2 = Angle(Angle::Degrees, deg2);
  Angle a1_p_a2 = a1 + a2;

  cout << "testAngle: " << deg1 << " deg + " << deg2 << " deg = " << a1_p_a2.get(Angle::Degrees) << endl;

  if (passed) {
    // check that a1 + a2 in degrees is equal to the degree wraparound of addition of deg1 and deg2
    passed = feq(a1_p_a2.get(Angle::Degrees), deg1 + deg2 - 360);
  }

  Angle a2_pe_a1 = Angle(Angle::Degrees, deg1);
  a2_pe_a1 += Angle(Angle::Degrees, deg2);

  cout << "testAngle: " << deg2 << " deg += " << deg1 << " deg: " << a2_pe_a1.get(Angle::Degrees) << endl;
  if (passed) {
    // check that the angle of a2 += a1 is equal to the degree wraparound of addition of deg1 and deg2
    passed = feq(a2_pe_a1.get(Angle::Degrees), deg1 + deg2 - 360);
  }

  cout << "testAngle: " << deg1 << " deg + " << deg2 << " deg to rad = " << a1_p_a2.get(Angle::Radians) << endl;
  if (passed) {
    // check that the radian angle of a1_p_a2 is equal to the proper radian amount
    passed = feq(a1_p_a2.get(Angle::Radians), M_PI / 180 * a1_p_a2.get(Angle::Degrees));
  }

  Angle a4 = Angle(Angle::Radians, rad1);
  Angle a5 = Angle(Angle::Radians, rad2);
  Angle a4_p_a5 = a4 + a5;

  cout << "testAngle: " << rad1 << " rad + " << rad2 << " rad = " << a4_p_a5.get(Angle::Radians) << endl;
  if (passed) {
    // check that a4 + a5 in radians is equal to the radian wraparound of addition of rad1 and rad2
    passed = feq(a4_p_a5.get(Angle::Radians), rad1 + rad2 - 2*M_PI);
  }

  Angle a5_pe_a4 = Angle(Angle::Radians, 1.9*M_PI);
  a5_pe_a4+= Angle(Angle::Radians, 0.2*M_PI);
  cout << "testAngle: " << rad2 << " rad += " << rad1 << " rad = " << a5_pe_a4.get(Angle::Radians) << endl;
  if (passed) {
    // check that a5 += a4 in radians is equal to the radian wraparound of addition of rad1 and rad2
    passed = feq(a5_pe_a4.get(Angle::Radians), rad1 + rad2 - 2*M_PI);
  }

  cout << "testAngle: " << rad1 << " rad + " << rad2 << " rad to deg = " << a4_p_a5.get(Angle::Degrees) << endl;
  if (passed) {
    // check that the degree angle of a4_p_a5 is equal to the proper degree amount
    passed = feq(a4_p_a5.get(Angle::Degrees), 180 / M_PI * a4_p_a5.get(Angle::Radians));
  }


  if (passed) {
    return TEST_PASSED;
  } else {
    return TEST_FAILED;
  }
//  return TEST_UNDEFINED;
}
