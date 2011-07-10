#include "CAngle.h"
#include <cmath>

/* TODO: preserve angle type (degrees, radians) */
/* TODO: allow addition using a double, using the current angle type */

#include <iostream>
using std::cout; using std::endl;

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

double Angle::fmod(double x, double y) { return x - y * floor(x / y); }

Angle::Angle(double radians) :
  angle_r(radians)
{
}

Angle Angle::radians(double radians)
{
  return Angle(radians);
}

Angle Angle::degrees(double degrees)
{
  return Angle(degrees*M_PI/180);
}

double Angle::getRadians() const
{
  return angle_r;
}

double Angle::getDegrees() const
{
  return angle_r*180/M_PI;
}

void Angle::setRadians(double radians)
{
  angle_r = radians;
}

void Angle::setDegrees(double degrees)
{
  angle_r = degrees*M_PI/180;
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
