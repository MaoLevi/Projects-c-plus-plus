#pragma once
#include <iostream>
using namespace std;
class List2
{
	//  inner class link
	//  a single element for the linked List 

	class Link
	{
	public:

		Link(int linkValue, Link* nextPtr); // constructor

		int value; // data of the first value 
		Link* next;
	};

public:

	List2(); // constructors
	List2(const List2&);
	~List2();
	List2 operator=(const List2& L);

	// operations
	void add(int value);
	int firstElement();
	bool search(const int& value) const;
	bool isEmpty()const;
	void removeFirst();
	void clear();
	friend ostream& operator<<(ostream& os, const List2& L);
	friend istream& operator>>(istream& is, List2& L);
	void insert(int key);
	void remove(int key);

protected:
	// data field
	Link* head;
};

