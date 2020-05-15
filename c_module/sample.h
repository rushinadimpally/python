#include <math.h>

extern "C" {
extern "C" int gcd(int x, int y);
extern "C" int in_mandel(double x0, double y0, int n);
extern "C" int divide(int a, int b, int *remainder);
extern "C" double avg(double *a, int n);

extern "C" struct Point
{
  double x;
  double y;
};

extern "C" double distance(Point *p1, Point *p2);
}
