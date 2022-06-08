#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP
#include "Triangle.h"
#include "TriangleError.h"

template <typename T>
Triangle<T>::Triangle(T first, T second, T third)
try : side1(first), side2(second), side3(third)
{
	if (!(side1 > 0 && side2 > 0 && side3 > 0))
	{
		throw TriangleError(1);
	}
	else if (!((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2)))
	{
		throw TriangleError(2);
	}
}
catch (...)
{
	throw;
}

template <typename T>
T Triangle<T>::calcArea()
{
	double halfSum = (side1 + side2 + side3) / 2;
	return (sqrt(halfSum * (halfSum - side1) * (halfSum - side2) * (halfSum - side3)));
}

template <typename T>
T Triangle<T>::calcPerimeter() const
{
	return (side1 + side2 + side3);
}

#endif