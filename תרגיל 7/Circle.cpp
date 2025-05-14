#include "Circle.h"
const float PI = 3.14;
Circle::Circle(float r):Shape(1)
{
	radius = r;
}

Circle::Circle(const Circle& E):Shape(E)
{
	radius = E.radius;
}

bool Circle::isSpecial() const
{
	if((arr[0].getPointx()==0&& arr[0].getPointy()==0))//checking if the circle is special
		return true;
	else
		return false;
}

void Circle::printSpecial() const
{
	
	if (this->isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}

double Circle::area() const
{
	return (radius*radius*PI);//calculate the area
}
