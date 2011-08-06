#ifndef CANGLE_H
#define CANGLE_H

#include "math.h"

#include <vector>
using std::vector;

class Angle
{
public:
  enum Unit{Radians, Degrees};
private:
  struct per_unit_data_t
  {
    double angle;
    double range_min;
    double range_max;
  } per_unit_data[2];

  Unit unit;

  static double convert(Unit from_unit, Unit to_unit, double angle);

  static double circle[2];

  void setUnit(Unit unit);
public:
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
