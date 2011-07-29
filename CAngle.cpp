#include "CAngle.h"
#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

double Angle::fmod(double a, double n, double m)
{
  return a - n * floor((a - m) / (n - m));
}

/* this is static, not part of per_unit_data,
   since it's used in a static function (convert) */
double Angle::circle[2] = {2*M_PI, 360};

double Angle::convert(Unit from_unit, Unit to_unit, double angle)
{
  double converted = angle * circle[to_unit] / circle[from_unit];
  return converted;
}

Angle::Angle(Unit unit, double angle)
: unit(unit)
{
  /* initialize default ranges */
  data = &(per_unit_data[Degrees]);
  data->range_min = 0;
  data->range_max = 360;
  data = &(per_unit_data[Radians]);
  data->range_min = 0;
  data->range_max = 2*M_PI;
  /* now set data pointer to specified unit */
  data = &(per_unit_data[unit]);
  /* set the angle now that the unit has been set */
  set(angle);
}

void Angle::setUnit(Unit unit)
{
  this->unit = unit;
  data = &(per_unit_data[unit]);
}

double Angle::get(Unit unit) const
{
  double angle = per_unit_data[unit].angle;
  return angle;
}

/* set(Unit, double) sets the unit and then calls set(double) */
void Angle::set(Unit unit, double angle)
{
  setUnit(unit); // declare that the angle has been set using a new unit
  set(angle);
}

double Angle::get() const
{
  return get(getUnit());
}

/* set(double) directly sets the angle using the current unit and converts to other unit */
void Angle::set(double angle)
{
  per_unit_data[getUnit()].angle = angle;
  Unit other_unit = getUnit() == Degrees? Radians: Degrees;
  per_unit_data[other_unit].angle = convert(getUnit(), other_unit, angle);
}

Angle::Unit Angle::getUnit() const
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
  cout << "operator+=: called with (" << get() << ", " << rhs.get(getUnit()) << ");" << endl;
  double new_angle = get() + rhs.get(getUnit());
  double fmod_angle = fmod(new_angle, data->range_max, data->range_min);
  cout << "operator+=: fmod(" << new_angle << ", " << data->range_max << ", " << data->range_min << ") = " << fmod_angle << endl;
  set(fmod_angle);
  cout << "operator+=: returning " << get() << endl;
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  set(get() - rhs.get(getUnit()));
  set(fmod(get(), data->range_max, data->range_min));
  return *this;
}

const Angle Angle::operator+(const Angle &other) const
{
  Angle result = *this;
  cout << "operator+: Calling operator+=(" << result.get() << ", " << other.get() << ");" << endl;
  result += other;
  cout << "operator+: result = " << result.get() << endl;
  return result;
}

const Angle Angle::operator-(const Angle &other) const
{
  return Angle(*this) -= other;
}
