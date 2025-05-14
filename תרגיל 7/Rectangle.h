#include "Shape.h"
#pragma once
class Rectangle:public Shape
{
public:
	Rectangle();
	 bool isSpecial() const override;
	void printSpecial() const override;
	double area() const override;
};

