#include "CPoint.h"
#include <iostream>
using std::cout;

Point::Point(double x, double y) :
  x(x), y(y)
{
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

void Point::print()
{
  cout << *this;
}

ostream& operator<<(ostream& os, const Point& p)
{
  os << "(" << p.x << "," << p.y << ")";
  return os;
}
