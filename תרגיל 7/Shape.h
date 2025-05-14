#pragma once
#include "Point.h"
#include <iostream>
using namespace std;
class Shape
{
protected:
	int numOfPoints;
	Point* arr;
public:
	Shape();//empty constructor
	Shape(int num);// constructor
	Shape(const Shape& E);//copy constructor
	friend ostream& operator <<(ostream& os,const Shape& E);
	Shape(const Shape&& E);
	virtual ~Shape();
	virtual double area() const=0;
	virtual bool isSpecial() const = 0;
	virtual void printSpecial() const = 0;
	
};

