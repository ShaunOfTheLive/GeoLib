#include "CPoint.h"
#include "CLine.h"
#include "CPolygon.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Polygon p1(Point(0.9, -2.64), Point(4.4, -1.86), 7);
  cout << p1 << endl;
  return 0;
}
