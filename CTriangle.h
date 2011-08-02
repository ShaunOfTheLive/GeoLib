#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CPoint.h"
#include "CAngle.h"
#include "CLineSegment.h"

class Triangle
{
  Point point1;
  Point point2;
  Point point3;

  void init(LineSegment,        Point);
  void init(LineSegment,        Angle, Angle);
  void init(LineSegment,        int length1, int length2);
  void init(LineSegment,        int length1, Angle);
public:
  Triangle(Point, Point, Point);
  Triangle(LineSegment,         Point);
  Triangle(Point, Point, Angle, Angle);
  Triangle(LineSegment,         Angle, Angle);
  Triangle(Point, Point, int length1, int length2);
  Triangle(LineSegment,         int length1, int length2);
  Triangle(Point, Point, int length1, Angle);
  Triangle(LineSegment,         int length1, Angle);
  // Triangle(Point, Point, Angle, int area);
  // Triangle(LineSegment,         Angle, int area);
  // Triangle(Point, Point, Angle, int perimeter);
  // Triangle(LineSegment,         Angle, int perimeter);

  Point getPoint(int pnum);
  void print();
  friend ostream&
      operator<<(ostream& os, const Triangle& t);
};

#endif
