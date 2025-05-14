#pragma once

class Point
{
	int x;
	int y;
public:
	Point();
	Point (int myx, int myy);
	Point(const Point& point1);
	void setPointx(int myx);
	void setPointy(int myy);
	int getPointx();
	int getPointy();
	double between(Point a, Point b);
};

