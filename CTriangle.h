#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CPoint.h"
#include "CAngle.h"
#include "CLine.h"

class Triangle
{
  Point point1;
  Point point2;
  Point point3;

  void init(Line,        Point);
  void init(Line,        Angle, Angle);
  void init(Line,        int length1, int length2);
  void init(Line,        int length1, Angle);
public:
  Triangle(Point, Point, Point);
  Triangle(Line,         Point);
  Triangle(Point, Point, Angle, Angle);
  Triangle(Line,         Angle, Angle);
  Triangle(Point, Point, int length1, int length2);
  Triangle(Line,         int length1, int length2);
  Triangle(Point, Point, int length1, Angle);
  Triangle(Line,         int length1, Angle);
  // Triangle(Point, Point, Angle, int area);
  // Triangle(Line,         Angle, int area);
  // Triangle(Point, Point, Angle, int perimeter);
  // Triangle(Line,         Angle, int perimeter);

  Point getPoint(int pnum);
  void print();
  friend ostream&
      operator<<(ostream& os, const Triangle& t);
};

#endif
