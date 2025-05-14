#include "Shape.h"
#pragma once
class Circle :public Shape
{
	float radius;

public:
	Circle(float r);//empty constructor
	Circle(const Circle& E);//constructor
	 bool isSpecial() const override;
	 void printSpecial() const override;
	 double area() const override;
};

