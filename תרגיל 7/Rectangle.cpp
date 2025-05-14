#include "Rectangle.h"

Rectangle::Rectangle():Shape(4){}

bool Rectangle::isSpecial() const
{
	double ab = arr[0].between(arr[1]);
	double  bc = arr[1].between(arr[2]);
	double cd = arr[2].between(arr[3]);
	double ad= arr[0].between(arr[3]);
	if (ab == bc&& bc== cd&&cd == ad)
		return true;
	else
		return false;
	
}

void Rectangle::printSpecial() const
{
	double ab = arr[0].between(arr[1]);
	if (this->isSpecial())
		cout << "Square with side length " << ab;
}

double Rectangle::area() const
{
	double ab = arr[0].between(arr[1]);
	double ad = arr[0].between(arr[3]);
	return (ab*ad);
}
