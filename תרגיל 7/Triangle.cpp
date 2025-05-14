#include "Triangle.h"
#include <cmath>

Triangle::Triangle():Shape(3){}

bool Triangle::isSpecial() const
{
	double ab= arr[0].between(arr[1]);
	double  ac= arr[1].between(arr[2]);
	double bc = arr[0].between(arr[2]);
	if (ab == ac == bc)
		return true;
	else
		return false;
}

void Triangle::printSpecial() const
{
	double ab = arr[0].between(arr[1]);
	if (this->isSpecial())
		cout << "A equilateral triangle with a side length " << ab << endl;
}

double Triangle::area() const//calculate the area
{
	double ab = arr[0].between(arr[1]);
	double  ac = arr[1].between(arr[2]);
	double bc = arr[0].between(arr[2]);
	double s = (ab + ac + bc) / 2;

	return (sqrt((s*(s-ab)*(s-ac)*(s-bc))));
}

