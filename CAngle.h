#ifndef CANGLE_H
#define CANGLE_H

class Angle
{
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

  void setUnit(Unit unit);
public:
  enum Unit{Radians, Degrees};

  Angle(Unit unit, double angle);

  double get(Unit unit) const;
  void set(Unit unit, double angle);
  double get() const;
  void set(double angle);
  Unit getUnit() const;
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
