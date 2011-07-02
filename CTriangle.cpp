#include "CTriangle.h"
#include "CLine.h"

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

Triangle::Triangle(Point p1, Point p2, Point p3) :
  point1(p1), point2(p2), point3(p3)
{
  // Line l1(p1, p2);
  // init(l1, p3);
}

Triangle::Triangle(Line l1,            Point p3) :
  point1(l1.getPoint1()), point2(l1.getPoint2()), point3(p3)
{
  // init(l1, p3);
}

void Triangle::init(Line l1,           Point p3)
{
}

Triangle::Triangle(Point p1, Point p2, Angle a1, Angle a2) :
  point1(p1), point2(p2), point3(0,0)
{
  Line l1(p1, p2);
  init(l1, a1, a2);
}

Triangle::Triangle(Line l1,            Angle a1, Angle a2) :
  point1(l1.getPoint1()), point2(l1.getPoint2()), point3(0,0)
{
  init(l1, a1, a2);
}

void Triangle::init(Line l1,           Angle a1, Angle a2)
{
  Angle orientation_l2 = Angle::degrees(l1.getOrientationA().getDegrees() - a1.getDegrees());
  double length_l2((l1.getLength() * a2.sin()) / Angle::degrees(180 - a1.getDegrees() - a2.getDegrees()).sin());
  Line l2(l1.getPoint1(), length_l2, orientation_l2);
  point3 = l2.getPoint2();
}

Triangle::Triangle(Point p1, Point p2, int length1, int length2) :
  point1(p1), point2(p2), point3(0,0)
{
  Line l1(p1, p2);
  init(l1, length1, length2);
}

Triangle::Triangle(Line l1,            int length1, int length2) :
  point1(l1.getPoint1()), point2(l1.getPoint2()), point3(0,0)
{
  init(l1, length1, length2);
}

void Triangle::init(Line l1,           int length1, int length2)
{
  Angle a1 = Angle::radians(acos((pow(l1.getLength(),2)+pow(length1,2)-pow(length2,2))/(2*l1.getLength()*length1)));
  Angle orientation_l2 = l1.getOrientationA() - a1;
  Line l2(l1.getPoint1(), length1, orientation_l2);
  point3 = l2.getPoint2();
}

Triangle::Triangle(Point p1, Point p2, int length1, Angle a1) :
  point1(p1), point2(p2), point3(0,0)
{
  Line l1(p1, p2);
  init(l1, length1, a1);
}

Triangle::Triangle(Line l1,            int length1, Angle a1) :
  point1(l1.getPoint1()), point2(l1.getPoint2()), point3(0,0)
{
  init(l1, length1, a1);
}

void Triangle::init(Line l1,           int length1, Angle a1)
{
  Angle orientation_l2 = l1.getOrientationA() - a1;
  Line l2(l1.getPoint1(), length1, orientation_l2);
  point3 = l2.getPoint2();
}

Point Triangle::getPoint(int pnum)
{
  switch (pnum) {
    case 1:
    return point1;
    break;
    case 2:
    return point2;
    break;
    case 3:
    return point3;
    break;
  }
}

void Triangle::print()
{
  // cout << "[" << point1 << "," << point2 << "," << point3 << "]";
  cout << *this;
}

ostream& operator<<(ostream& os, const Triangle& t)
{
  os << "[" << t.point1 << "," << t.point2 << "," << t.point3 << "]";
  return os;
}
