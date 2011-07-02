#ifndef CPOINT_H
#define CPOINT_H
#include <iostream>
using std::ostream;

class Point
{
  double x;
  double y;
public:
  Point(double x, double y);
  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  void print();
  friend ostream&
    operator<<(ostream& os, const Point& p);
};

#endif
