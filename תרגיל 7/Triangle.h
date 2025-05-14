#include "Shape.h"
#pragma once
class Triangle:public Shape
{
public:
	Triangle();//empty constructor
	bool isSpecial() const override;
    void printSpecial() const override;
    double area() const override;
};

