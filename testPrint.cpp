void testPrint()
{
  cout << "***************\n";
  cout << "** testPrint **\n";
  cout << "***************";
  cout << endl;
  Point p1(2,5);
  cout << p1 << endl;
  LineSegment l1(p1,Point(7,8));
  cout << l1 << endl;
  Triangle t1(l1, Point(4.97,4.56));
  cout << t1 << endl;
}
