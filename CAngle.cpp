#include "CAngle.h"
#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

double Angle::fmod(double a, double n, double m) {
  return a - n * floor((a - m) / n);
}

double convert(Unit from_unit, Unit to_unit, double angle)
{
  double converted = angle * per_unit_data[to_unit].circle / per_unit_data[from_unit].circle;
  return converted;
}

Angle::Angle(Unit unit, double angle)
: unit(unit),
  per_unit_data[Degrees].range_min = 0,   per_unit_data[Radians].range_min = 0,
  per_unit_data[Degrees].range_max = 360, per_unit_data[Radians].range_max = 2*M_PI,
  per_unit_data[Degrees].circle =    360, per_unit_data[Radians].circle    = 2*M_PI
{
  data = &per_unit_data[unit];
  set(angle);
}

void Angle::setUnit(Unit unit)
{
  this->unit = unit;
  data = &per_unit_data[unit];
}

double Angle::get(Unit unit) const
{
  double angle = per_unit_data[unit].angle;
  return angle;
}

/* set(Unit, angle) sets the unit and then calls set(double) */
void Angle::set(Unit unit, double angle)
{
  setUnit(unit); // declare that the angle has been set using a new unit
  set(angle);
}

double Angle::get() const
{
  return get(getUnit());
}

/* set(double) directly sets the angle using the current unit */
void Angle::set(double angle)
{
  data->angle = angle;
  Unit other_unit = getUnit() == Degrees? Radians: Degrees;
  per_unit_data[other_unit].angle = convert(getUnit(), other_unit, angle);
}

Unit Angle::getUnit() const
{
  return this->unit;
}

vector<double> Angle::getRange() const
{
  vector<double> range;
  range.push_back(data->range_min);
  range.push_back(data->range_max);
  return range;
}

void Angle::setRange(double min, double max)
{
  data->range_min = min;
  data->range_max = max;
  Unit other_unit = getUnit() == Degrees? Radians: Degrees;
  per_unit_data[other_unit].range_min = convert(getUnit(), other_unit, min);
  per_unit_data[other_unit].range_max = convert(getUnit(), other_unit, max);
}

double Angle::cos() const
{
  double cos = std::cos(get(Radians));
  return cos;
}

double Angle::sin() const
{
  double sin = std::sin(get(Radians));
  return sin;
}

Angle Angle::operator+=(const Angle &rhs)
{
  set(get() + rhs.get());
  set(fmod(get(), data->range_max));
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  set(get() - rhs.get());
  set(fmod(get(), data->range_max));
  return *this;
}

const Angle Angle::operator+(const Angle &other) const
{
  return Angle(*this) += other;
}

const Angle Angle::operator-(const Angle &other) const
{
  return Angle(*this) -= other;
}
