#include "Shape.h"
#include <iostream>
using namespace std;
Shape::Shape()
{
	numOfPoints = 0;
	arr = nullptr;
}

Shape::Shape(int num):Shape()
{
	arr = new Point[num];
	numOfPoints = num;
	cout << "Enter values of " << num << " points: " << endl;
	for (int i = 0;i < num;i++) {
		cin >> arr[i];
	}
}

Shape::Shape(const Shape& E)
{
	numOfPoints = E.numOfPoints;
	for (int i = 0;i < E.numOfPoints;i++) {
		arr[i] = E.arr[i];
	}
}

Shape::Shape(const Shape&& E)
{
	arr = E.arr;
	numOfPoints = E.numOfPoints;
}

Shape::~Shape()
{
	numOfPoints = 0;
	delete arr;
}

ostream& operator<<(ostream& os,const Shape& E)
{
	cout << "points: ";
	for (int i = 0;i < E.numOfPoints;i++) {
		cout <<'('<< E.arr[i].getPointx()<<','<< E.arr[i].getPointy()<<") ";
	}
	// TODO: insert return statement here
	return os;
}
