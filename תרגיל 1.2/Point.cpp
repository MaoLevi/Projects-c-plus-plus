#include "Point.h"
#include <cmath>
#include <iostream>
/*
maor levi
328301981
sadna
targil#2-1
the program recieve from the user value of point and create strangle
the program colculte the value of the scope and othe thing
at the begining you ask why we didnt need function destory,the answer is
because we didnt need to destory nothing we have just a point not arr.
the answer of the second question is because we use in the set function of the point
*/
using namespace std;
Point::Point()
{
	y = 0, x = 0;
}
Point:: Point(int myx, int myy) {
	x = myx;
	y = myy;
}
void Point::setPointx(int myx)
{
	x = myx;
}
void Point::setPointy(int myy)
{
	y = myy;
}
double Point::between(Point a, Point b)
{
	return  (sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}
int Point:: getPointx() { return x; }
int Point:: getPointy() { return y; }
Point::Point(const Point& point1)
{
	
	x = point1.x;
	y = point1.y;
}

