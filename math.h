#ifndef GEOLIB_MATH_H
#define GEOLIB_MATH_H

#include <cmath>

#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

#ifndef EPSILON
#define EPSILON 0.000001
#endif

inline double fmod(double a, double n, double m = 0)
{
  return a - n * floor((a - m) / (n - m));
}

/*
#define feq(x, y) (fabs((x)-(y))<EPSILON)
*/

inline bool feq(double x, double y) {
  return (fabs(x - y) < EPSILON);
}

inline bool feq(float x, float y) {
  return (fabs(x - y) < EPSILON);
}

#endif
