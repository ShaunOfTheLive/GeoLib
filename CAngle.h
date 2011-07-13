#ifndef CANGLE_H
#define CANGLE_H

class Angle
{
  double angle_d;
  double angle_r;
  double rollover_d;
  double rollover_r;
  struct per_unit_data
  {
    double angle;
    double range_min;
    double range_max;
    double circle;
  }
  per_unit_data* data;
  Unit unit;
  static double fmod(double x, double y);
  static double convert(Unit from_unit, Unit to_unit, double angle);
public:
  enum Unit{Radians, Degrees};

  Angle(Unit unit, double angle);

/* deprecated */
  double getRadians() const;
  void setRadians(double radians);
  double getDegrees() const;
  void setDegrees(double degrees);
/* */
  double get(Unit unit) const;
  void set(Unit unit, double angle);
  double get() const;
  void set(double angle);
  Unit getUnit() const;
  void setUnit(Unit unit);
  vector<double> getRange() const;
  void setRange(double min, double max);
  double cos() const;
  double sin() const;

  Angle operator+=(const Angle &rhs);
  Angle operator-=(const Angle &rhs);
  const Angle operator+(const Angle &other) const;
  const Angle operator-(const Angle &other) const;
};

#endif
