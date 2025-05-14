#pragma once
#include <iostream>
using namespace std;

const int DEF_CAPACITY = 100;


class Vector
{
protected:
	int* data;
	int size;		//size in use
	int capacity;	//available capacity
public:

	Vector(int capacity = DEF_CAPACITY); //constructors
	Vector(const Vector& v);
	~Vector();

	Vector& operator= (const Vector&); //operations

	int operator[](int index); //modify
	// cheak const T& operator[](int index) const;
	int	getSize() const;
	int  getCapacity() const;
	void insert(int value);
	void  clear();
	int  delLast();
	bool isEmpty() const;


};

