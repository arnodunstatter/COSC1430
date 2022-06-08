#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cmath>
#include <iomanip>
#include "triangleError.h"

template <typename T> //can work with doubles, long doubles, long longs, etc
class Triangle
{
private:
	T side1, side2, side3;
public:
	Triangle(T side1, T side2, T side3);
	T calcArea();
	T calcPerimeter() const;
};
#endif
