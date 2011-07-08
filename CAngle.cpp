#include "CAngle.h"
#include <cmath>

/* TODO: preserve degrees */

#include <iostream>
using std::cout; using std::endl;

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

double Angle::fmod(double x, double y) { return x - y * floor(x / y); }

Angle::Angle(double radians) :
  angler(radians)
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
  return angler;
}

double Angle::getDegrees() const
{
  return angler*180/M_PI;
}

void Angle::setRadians(double radians)
{
  angler = radians;
}

void Angle::setDegrees(double degrees)
{
  angler = degrees*M_PI/180;
}

double Angle::cos() const
{
  return std::cos(angler);
}

double Angle::sin() const
{
  return std::sin(angler);
}

Angle Angle::operator+=(const Angle &rhs)
{
  angler += rhs.angler;
  angler = fmod(angler,2*M_PI);
  return *this;
}

Angle Angle::operator-=(const Angle &rhs)
{
  angler -= rhs.angler;
  angler = fmod(angler,2*M_PI);
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
