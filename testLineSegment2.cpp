int testLineSegment2()
{
  vector<LineSegment*> lsv;
  /* test constructors */
  lsv.push_back(new LineSegment(Point(2, 4), Point(-3, -5)));
  vector<Point> pts;
  pts = lsv[0]->getPoints();
  cout << "LineSegment (2,4),(-3,-5): " << pts[0] << "; " << pts[1] << endl;

  return TEST_UNDEFINED;
}
