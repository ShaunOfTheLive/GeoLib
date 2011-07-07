void testLineSegment1()
{
  cout << "**********************\n";
  cout << "** testLineSegment1 **\n";
  cout << "**********************";
  cout << endl;
  cout.precision(2);
  Triangle t11(Point(2,5),Point(7,8),Angle::degrees(39.49),Angle::degrees(28.49));
  cout << t11 << endl;
  Triangle t12(LineSegment(Point(2,5),Point(7,8)),Angle::degrees(39.49),Angle::degrees(28.49));
  cout << t12 << endl;
  Triangle t13(LineSegment(Point(2,5),5.83,Angle::degrees(30.96)), Angle::degrees(39.49), Angle::degrees(28.49));
  cout << t13 << endl;
  Triangle t21(Point(2,5),Point(7,8),3,4);
  cout << t21 << endl;
  Triangle t22(LineSegment(Point(2,5),Point(7,8)),3,4);
  cout << t22 << endl;
  Triangle t23(LineSegment(Point(2,5),5.83,Angle::degrees(30.96)), 3, 4);
  cout << t23 << endl;
  Triangle t31(Point(2,5),Point(7,8),3,Angle::degrees(39.49));
  cout << t31 << endl;
  Triangle t32(LineSegment(Point(2,5),Point(7,8)),3,Angle::degrees(39.49));
  cout << t32 << endl;
  Triangle t33(LineSegment(Point(2,5),5.83,Angle::degrees(30.96)), 3, Angle::degrees(39.49));
  cout << t33 << endl;
}
