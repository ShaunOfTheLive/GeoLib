#ifndef CPOINT_H
#define CPOINT_H
#include <iostream>
using std::ostream;

class Angle;

class Point
{
  double x;
  double y;
  double r;
  Angle th;
  bool polar;
public:
  /* cartesian co-ordinates */
  Point(double x, double y);
  
  double getX() const;
  double getY() const;
  void setX(double x);
  void setY(double y);

  /* polar co-ordinates */
  Point(double r, Angle th);

  double getR() const;
  Angle getTh() const;
  void setR(double r);
  void setTh(Angle th);

  void print();
  friend ostream&
    operator<<(ostream& os, const Point& p);
};

#endif
