#include "CPoint.h"
#include <iostream>
using std::cout;

class Angle;

Point::Point(double x, double y) :
  x(x), y(y)
{
  polar = false;
}

double Point::getX() const
{
  return x;
}

double Point::getY() const
{
  return y;
}

void Point::setX(double x)
{
  this->x = x;
}

void Point::setY(double y)
{
  this->y = y;
}

Point::Point(double r, Angle th) :
  r(r), th(th)
{
  polar = true;
}

double Point::getR() const
{
  return r;
}

Angle Point::getTh() const
{
  return th;
}

void Point::setR(double r)
{
  this->r = r;
}

void Point::setTh(Angle th)
{
  this->th = th;
}
void Point::print()
{
  cout << *this;
}

ostream& operator<<(ostream& os, const Point& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
