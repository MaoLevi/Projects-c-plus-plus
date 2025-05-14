#pragma once
#include <iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	Point();//empty constructor
	Point(int myx, int myy);//constructor
	Point(const Point& point1);//copy constructor
	void setPointx(int myx);
	void setPointy(int myy);
	int getPointx();
	int getPointy();
	friend istream& operator>>(istream& is, Point& E);
	double between(Point a);
};

