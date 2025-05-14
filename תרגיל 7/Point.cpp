#include "Point.h"
#include <cmath>
#include <iostream>

using namespace std;
Point::Point()
{
	y = 0, x = 0;
}
Point::Point(int myx, int myy) {
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
double Point::between(Point a)
{
	return  (sqrt((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y)));//calculating the distance between two points 
}
int Point::getPointx() { return x; }
int Point::getPointy() { return y; }
Point::Point(const Point& point1)
{

	x = point1.x;
	y = point1.y;
}
istream& operator>>(istream& is, Point& E)
{
	char a;
	int x, y;
	is >> a >> x >> a >> y >> a;
	E.x = x;
	E.y= y;
	return is;
}
