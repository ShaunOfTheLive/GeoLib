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

double convertToDeg(double radians) {
  double degrees = radians * 180 / M_PI;
  return degrees;
}

double convertToRad(double degrees) {
  double radians = degrees * M_PI / 180;
  return radians;
}

Angle::Angle(Unit unit, double angle)
: unit(unit), rollover_d(360), rollover_r(2*M_PI)
{
  set(unit, angle);
}

double Angle::getRadians() const
{
  return angle_r;
}

double Angle::getDegrees() const
{
  return angle_d;
}

double Angle::get(Unit unit) const
{
  double retval;
  switch(unit) {
  case Radians:
    retval = angle_r;
    break;
  case Degrees:
    retval = angle_d;
    break;
  default:
    throw "Unit must be Radians or Degrees";
  }
  return retval;
}

void Angle::setRadians(double radians)
{
  angle_r = radians;
  angle_d = convertToDeg(radians);
}

void Angle::setDegrees(double degrees)
{
  angle_d = degrees;
  angle_r = convertToRad(degrees);
}

void Angle::set(Unit unit, double angle)
{
  switch(unit) {
  case Radians:
    angle_r = angle;
    angle_d = convertToDeg(angle);
    break;
  case Degrees:
    angle_d = angle;
    angle_r = convertToRad(angle);
    break;
  default:
    throw "Unit must be Radians or Degrees";
  }
}

double get() const
{
  return get(getUnit());
}

void set(double angle)
{
  set(getUnit(), angle);
}

Unit getUnit() const
{
  return this->unit;
}

void setUnit(Unit unit)
{
  this->unit = unit;
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
  set(fmod(get(), getUnit() == Degrees? rollover_d: rollover_r)); // angle_r = fmod(angle_r,2*M_PI);
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  set(get() - rhs.get());  //angle_r -= rhs.angle_r;
  set(fmod(get(), getUnit() == Degrees? rollover_d: rollover_r)); // angle_r = fmod(angle_r,2*M_PI);
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
