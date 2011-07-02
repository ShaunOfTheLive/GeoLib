#ifndef CLINE_H
#define CLINE_H

class Angle;
class Line
{
  Point point1;
  Point point2;
  double slope;
public:
  Line(Point, Point);
  Line(Point, double length1, double orientation);
  Line(Point, double length1, Angle orientation);
  Point getPoint1() const;
  Point getPoint2() const;
  void setPoint1(Point);
  void setPoint2(Point);
  double getSlope() const;
  double getOrientation() const;
  Angle getOrientationA() const;
  double getLength() const;
  
  void print();
  friend ostream&
    operator<<(ostream& os, const Line& l);
};

#endif
