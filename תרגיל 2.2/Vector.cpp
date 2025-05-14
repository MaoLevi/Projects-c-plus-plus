#include "Vector.h"
#include<iostream>
#include <cmath>
using namespace std;
/*
328301981
maor levi
targil #2-2
sadna
the program create class by name vector that have size and maxsize and arr 
with value,the program make operation according what the user put
*/
Vector::Vector() {
	size = 0;
	capacity = 2;
	data = new int[capacity];
}
Vector::Vector(int capa) {
	float tri = capa;
	while (tri > 2)
		tri /= 2;
	if (tri == 2) {
		capacity = capa;
		data = new int[capacity];
		size = 0;
	}
	else {
		capacity = int(pow(2, ceil(log(capa) / log(2))));
		data = new int[capacity];
		size = 0;
	}
}
Vector::Vector(const Vector& vec) {
	capacity = vec.capacity;
	size = vec.size;
	data = new int[capacity];
	for (int i = 0; i < size; i++) {
		data[i] = vec.data[i];
	}
}

Vector::~Vector() {
	if (!data) {
		delete[]data;
		data = nullptr;
	}
}
int Vector::getCapacity() {
	return capacity;
}
int Vector::getSize() {
	return size;
}

void Vector::print() {
	cout << "capacity: " << capacity << " size: " << size << " values: ";
	for (int i = 0;i < size;i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

void Vector:: assign(Vector re) {
	for (int i = 0;i < size;i++) {
		data[i] = re.data[i];
	}
	size = re.size;
	capacity = re.capacity;
}
bool Vector::isEqual(Vector a) {
	int sum = 0;
	if (size != a.size)
		return false;
	else{
		for (int i = 0;i < size;i++) {
				if (data[i] == a.data[i]) 
					sum++;
				
		}
		if (sum == size) 
			return true;
		else
			return false;
	}
}
int& Vector::at(int index) {
	if ((index > size) || (index < 0)) {
		cout << "ERROR" << endl;
		return data[0];
	}
	else
		return data[index];
}
int Vector::scalmul(Vector a) {
	int sum = 0;
	if (a.size != size) {
		cout << "ERROR" << endl;
		return -1;
	}
	else
		for (int i = 0;i < size;i++) {
			sum += (a.data[i] * data[i]);
		}
	return sum;
}

Vector Vector::strnewcat(const Vector& a) {
	int num = 0;
	for (int i = size;i < (a.capacity-capacity - size);i++) {
		data[i] = a.data[num];
		num++;
	}
	size += a.size;
	Vector(capacity + a.capacity);
	a.capacity = capacity;
	return a;
}
void Vector::clear() {
	data = nullptr;
	size=0;
}
void Vector::delLast() {
	if (size == 0) {
		cout << "ERROR" << endl;
	}
	else {
		data[size - 1] = 0;
		size--;
	}
}
void Vector::insert(int val) {
	
	if (capacity> size) {
		data[size] = val;
		size++;
		return;
	}
	capacity *= 2;
	int* arr;
	arr = new int[capacity];
	for (int i = 0;i < size;i++) {
			arr[i] = data[i];
	}
	arr[size] = val;
	size++;
	data = arr;
}
/*
Test 1 - Constructors

v1 capacity: 4 v1 size: 0
v2 capacity: 16 v2 size: 0
v3 capacity: 2 v3 size: 0

Test 2 - Assign

v1 capacity: 4 v1 size: 4
v2 capacity: 16 v2 size: 4
v3 capacity: 4 v3 size: 4

Test 3 - Operations

enter your choice 0-8:
3
v1*v2=30
capacity: 4 size: 4 values: 1 2 3 4
capacity: 16 size: 4 values: 1 2 3 4
capacity: 4 size: 4 values: 5 6 7 8

enter your choice 0-8:
0
*/
