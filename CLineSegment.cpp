#include "CPoint.h"
#include "CLineSegment.h"
#include "CAngle.h"
#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

LineSegment::LineSegment(Point p1, Point p2) :
  point1(p1), point2(p2), slope((point2.getY()-point1.getY())/(point2.getX()-point1.getX()))
{
}

LineSegment::LineSegment(Point p1, double length1, double orientation) :
  point1(p1), point2(length1 * cos(orientation*M_PI/180) + p1.getX(), length1 * sin(orientation*M_PI/180) + p1.getY())
{
}

LineSegment::LineSegment(Point p1, double length1, Angle orientation) :
  point1(p1), point2(length1 * orientation.cos() + p1.getX(), length1 * orientation.sin() + p1.getY())
{
}

Point LineSegment::getPoint1() const
{
  return point1;
}

Point LineSegment::getPoint2() const
{
  return point2;
}

void LineSegment::setPoint1(Point p1)
{
  point1 = p1;
}

void LineSegment::setPoint2(Point p2)
{
  point2 = p2;
}

double LineSegment::getSlope() const
{
  return slope;
}

double LineSegment::getOrientation() const
{
  return atan2(point2.getY()-point1.getY(), point2.getX()-point1.getX()) * 180 / M_PI;
}

Angle LineSegment::getOrientationA() const
{
  return Angle::radians(atan2(point2.getY()-point1.getY(), point2.getX()-point1.getX()));
}

double LineSegment::getLength() const
{
  double f1 = pow(point2.getX() - point1.getX(),2);
  double f2 = pow(point2.getY() - point1.getY(),2);
  return sqrt(f1+f2);
  // return sqrt(pow(point2.getX()-point1.getX(),2)+pow(point2.getY()-point1.getY(),2));
}

void LineSegment::print()
{
  cout << *this;
}

ostream& operator<<(ostream& os, const LineSegment& l)
{
  os << "[" << l.getPoint1() << "," << l.getPoint2() << "]";
  return os;
}
