#ifndef CPOLYGON_H
#define CPOLYGON_H

#include "CPoint.h"
#include "CAngle.h"
#include "CLine.h"

#include <vector>

class Polygon
{
  std::vector<Point> points;
  int num_sides;

  void init(Line,       int num_sides);
public:
  Polygon(Point, Point, int num_sides);
  Polygon(Line,         int num_sides);

  Point getPoint(int pnum);
  void print();
  friend ostream&
      operator<<(ostream& os, const Polygon& t);
};

#endif
