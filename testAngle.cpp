int testAngle()
{
  cout << "***************\n";
  cout << "** testAngle **\n";
  cout << "***************";
  cout << endl;
  Angle a1 = Angle::degrees(280);
  Angle a2 = Angle::degrees(281);
  cout << a1.getDegrees() << " + " << a2.getDegrees() << " = " << (a1+a2).getDegrees() << endl;
  cout << "a2 was " << a2.getDegrees() << endl;
  a2 += Angle::degrees(89);
  cout << "added 89 deg and now it's " << a2.getDegrees() << endl;

  return TEST_UNDEFINED;
}
