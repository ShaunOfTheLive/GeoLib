#ifndef CANGLE_H
#define CANGLE_H

class Angle
{
  double angle_d;
  double angle_r;
  Unit unit;
  static double fmod(double x, double y);
  static double convertToDeg(double radians);
  static double convertToRad(double degrees);
public:
  Angle(Unit unit, double angle);

  enum Unit{Radians, Degrees};

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
};

#endif
