class Parallelogram
{
  Point point1;
  Point point2;
  Point point3;
public:
  Parallelogram(Point, Point, Point);
  Parallelogram(Point, Point, Angle, Angle);
  Parallelogram(Point, Point, Angle, int area);
  Parallelogram(Point, Point, Angle, int perimeter);
  Parallelogram(Vector, int length1, int length2);
  Parallelogram(Vector, int length1, Angle);
  Parallelogram(Vector, Angle, Angle);
  Parallelogram(Vector, Angle, int area);
  Parallelogram(Vector, Angle, int perimeter);
  Parallelogram(Point, Point, Angle, int length1, bool direction)
    // direction optional? direction just reverses the angle
    // i.e. 92 with opposite direction would be 360-92=268
};