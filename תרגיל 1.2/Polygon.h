#pragma once

#include "Point.h"
class Polygon
{
private:
	Point* vertex;
	int numvertex;
public:
	void addPoint(Point b, int place);
	Polygon();
	Polygon(int num);
	Polygon(const Polygon& vec);
	~Polygon();
	Point* getvec();
	int getnum();
	double scope();
	bool check(Polygon);
};

