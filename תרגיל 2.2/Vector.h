#pragma once
#include<iostream>
#include <cmath>
using namespace std;
class Vector
{
	int* data;
	int capacity;
	int size;
public:
	Vector();
	Vector(int capa);
	Vector(const Vector& vec);
	~Vector();
	int getCapacity();
	int getSize();
	Vector strnewcat(const Vector& vec);
	void print();
	void assign(Vector re);
	bool isEqual(Vector);
	int& at(int index);
	int scalmul(Vector);
	void clear();
	void delLast();
	void insert(int val);
};

