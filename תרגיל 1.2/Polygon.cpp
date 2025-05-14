#include "Polygon.h"
#include "Point.h"
#include <cstring>
#include <iostream>
using namespace std;
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
Polygon::Polygon()
{
	numvertex = 0;
	vertex = nullptr;
    cout << "in empty constructor" << endl;
}

Polygon::Polygon(int num)
{
	cout << "in one parameter constructor" << endl;
	numvertex = num;
	vertex = new Point[numvertex];
}

Polygon::~Polygon() {
	cout << "in destructor" << endl;
	if (numvertex) {
		delete[]vertex;
		vertex = nullptr;
		numvertex = 0;
	}
}

Point* Polygon::getvec()
{
	Point* arr = new Point[numvertex];
	for (int i = 0; i < numvertex; i++)
	{
		arr[i] = vertex[i];
	}
	return arr;
}
int Polygon::getnum(){
	return numvertex;
}

void Polygon::addPoint(Point b, int place)
{
	vertex[place].setPointx(b.getPointx());
	vertex[place].setPointy(b.getPointy());
}

double Polygon::scope()
{
	double sum = 0;
	for (int i = 0;i < numvertex-1;i++) {
		sum += vertex[i].between(vertex[i],vertex[i + 1]);
	}
	sum += vertex[0].between(vertex[0],vertex[numvertex - 1]);
	return sum;
}

bool Polygon::check(Polygon arr) {
	int sum = 0;
	for (int i = 0;i < numvertex;i++) {
		for (int j = 0;j < numvertex;j++) {
			if (arr.vertex[i].getPointx() == vertex[j].getPointx()) {
				if (arr.vertex[i].getPointy() == vertex[j].getPointy()) 
					sum++;
			}
		
		}
	}
	if (sum == numvertex) {
		return true;
	}
	else
		return false;
	
}
Polygon::Polygon(const Polygon& vec)
{
	numvertex = vec.numvertex;
	cout << "in copy constructor" << endl;
	vertex = new Point[numvertex];
	for (int i = 0; i < numvertex; i++)
	{
		vertex[i] = vec.vertex[i];
	}
	
}