#pragma once
#include "Point.h"
#include <string>
/*
maor levi
328301981
sadna
targil#1-3
the program recieve 3 circle and calculte the area and the center of them
the program ask from the user point and check if the point in the circlle

*/
class Circle
{
	Point center;
	int radius;
public:

	void setcenter(int x, int y);
	void setRadius(int myRadius);
	Point getcenter();
	int getRadius();
	double area();
	double perimeter();
	int onInOut(Point p);
};
