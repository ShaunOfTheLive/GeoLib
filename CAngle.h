#ifndef CANGLE_H
#define CANGLE_H

class Angle
{
  double angler;
  static double fmod(double x, double y);
public:
  static Angle radians(double radians);
  static Angle degrees(double degrees);
  double getRadians() const;
  double getDegrees() const;
  void setRadians(double radians);
  void setDegrees(double degrees);
  double cos() const;
  double sin() const;

  Angle operator+=(const Angle &rhs);
  Angle operator-=(const Angle &rhs);
  const Angle operator+(const Angle &other) const;
  const Angle operator-(const Angle &other) const;
private:
  Angle(double radians); /* constructor is private to force use of radians or degrees function */
};

#endif
