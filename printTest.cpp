#include "CPoint.h"
#include "CLine.h"
#include "CAngle.h"
#include "CTriangle.h"

#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Point p1(2,5);
  cout << p1 << endl;
  Line l1(p1,Point(7,8));
  cout << l1 << endl;
  Triangle t1(l1, Point(4.97,4.56));
  cout << t1 << endl;
  return 0;
}
