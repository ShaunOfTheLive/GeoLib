#include "CPolygon.h"
#include "CLine.h"
#include "CTriangle.h"

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>
#include <vector>
#include <exception>
using std::exception;

class NumSidesException: public exception
{
  virtual const char* what() const throw()
  {
    return "Error! Number of sides must be greater than or equal to 3.";
  }
} NumSidesEx;

Polygon::Polygon(Point p1, Point p2, int num_sides) :
  num_sides(num_sides)
{
  Line l1(p1, p2);
  init(l1, num_sides);
}

Polygon::Polygon(Line l1,            int num_sides) :
  num_sides(num_sides)
{
  init(l1, num_sides);
}

void Polygon::init(Line l1,          int num_sides)
{
  points.push_back(l1.getPoint1());
  points.push_back(l1.getPoint2());
  cout << "point1 : " << l1.getPoint1() << endl;
  cout << "points[0] : " << points[0] << endl;
  cout << "point2 : " << l1.getPoint2() << endl;
  cout << "points[1] : " << points[1] << endl;
  double length = l1.getLength();
  cout << "length = " << length << endl;
  Angle orientation = l1.getOrientationA();
  Angle interangle = Angle::degrees(180-(360/num_sides));
  if (num_sides < 3) throw NumSidesEx;
  for (int i = 2; i < num_sides; i++) {
    Triangle t(points[i-2],points[i-1],length,interangle);
    cout << t << endl;
    points.push_back(t.getPoint(3));
  }
}

Point Polygon::getPoint(int pnum)
{
  return points[pnum];
}

void Polygon::print()
{
  // cout << "[" << point1 << "," << point2 << "," << point3 << "]";
  cout << *this;
}

ostream& operator<<(ostream& os, const Polygon& t)
{
  os << "[";
  for (int i = 0; i < t.num_sides; i++) {
    os << t.points[i];
    if (i < t.num_sides - 1) {
      os << ",";
    }
  }
  os << "]";
  // os << "[" << t.point1 << "," << t.point2 << "," << t.point3 << "]";
  return os;
}
