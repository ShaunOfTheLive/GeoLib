void testLineSegment2()
{
  cout << "**********************\n";
  cout << "** testLineSegment2 **\n";
  cout << "**********************";
  cout << endl;
  vector<LineSegment*> lsv;
  /* test constructors */
  lsv.push_back(new LineSegment(Point(2, 4), Point(-3, -5)));
  vector<Point> pts;
  pts = lsv[0]->getPoints();
  cout << "LineSegment (2,4),(-3,-5): " << pts[0] << "; " << pts[1] << endl;
}
