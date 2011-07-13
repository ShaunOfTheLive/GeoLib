#include "CAngle.h"
#include <cmath>

#include <iostream>
using std::cout;
using std::endl;

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

double Angle::fmod(double x, double y) {
  return x - y * floor(x / y);
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
  set(unit, angle);
  data = &per_unit_data[unit];
}

double Angle::getRadians() const
{
  return get(Radians);
}

double Angle::getDegrees() const
{
  return get(Degrees);
}

void Angle::setRadians(double radians)
{
  set(Radians, radians);
}

void Angle::setDegrees(double degrees)
{
  set(Degrees, degrees);
}

double Angle::get(Unit unit) const
{
  setUnit(unit);
  return get();
}

/* set(Unit, angle) sets the unit and then calls set(double) */
void Angle::set(Unit unit, double angle)
{
  setUnit(unit);
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
}

Unit Angle::getUnit() const
{
  return this->unit;
}

void Angle::setUnit(Unit unit)
{
  this->unit = unit;
  data = &per_unit_data[unit];
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
}

double Angle::cos() const
{
  return std::cos(angle_r);
}

double Angle::sin() const
{
  return std::sin(angle_r);
}

Angle Angle::operator+=(const Angle &rhs)
{
  set(get() + rhs.get());  //angle_r += rhs.angle_r;
  set(fmod(get(), data->range_max)); // angle_r = fmod(angle_r,2*M_PI);
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  set(get() - rhs.get());  //angle_r -= rhs.angle_r;
  set(fmod(get(), data->range_max)); // angle_r = fmod(angle_r,2*M_PI);
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
