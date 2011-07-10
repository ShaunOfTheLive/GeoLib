#include "CAngle.h"
#include <cmath>

/* TODO: preserve angle type (degrees, radians) */
/* TODO: allow addition using a double, using the current angle type */

#include <iostream>
using std::cout; using std::endl;

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

double Angle::getRadians() const
{
  return angle_r;
}

double Angle::getDegrees() const
{
  return angle_d;
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
  angle_r += rhs.angle_r;
  angle_r = fmod(angle_r,2*M_PI);
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  angle_r -= rhs.angle_r;
  angle_r = fmod(angle_r,2*M_PI);
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
