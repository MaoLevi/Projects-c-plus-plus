#include "List2.h"
#include <iostream>
using namespace std;
List2::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}
//--------------------------------------------
//  class List implementation
//--------------------------------------------
List2::List2() :head(nullptr) {}





List2::List2(const List2& l)
{

	Link* src, * trg;
	if (l.head == nullptr)
		head = nullptr;
	else
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

List2::~List2()
{
	clear();
}

List2 List2::operator=(const List2& L)
{
	if (this != &L)
	{
		Link* p = head;
		while (p)
		{
			Link* next = p->next;
			delete p;
			p = next;
		}
		head = nullptr;

		Link* a = L.head;
		while (a)
		{
			add(a->value);
			a = a->next;
		}

	}

	return *this;
}

void List2::clear()
{
	while (!isEmpty())
	{
		removeFirst();
	}
}

void List2::insert(int key)
{

	if (this->isEmpty()) {
		head = new Link(key, head);
	}
	else {
		Link* check = head;
		while (check->next != nullptr)
		{
			check = check->next;
		}
		Link* p = head;
		if (p->next == nullptr) {
			if (p->value < key)
				head = new Link(key, head);
			else
				p->next = new Link(key, p);
			return;
		}
		if (key > p->value) {
			head = new Link(key, head);
			return;
		}
		if (key < check->value) {
			check->next = new Link(key, check);
			return;
		}

		while (p->next != nullptr) {
			if (p->value <= key && p->next->value >= key)
			{
				p->next = new Link(key, p);
				return;
			}
			p = p->next;
		}
	}


}

void List2::remove(int key)
{
	Link* p = head;
	Link* temp = nullptr;
	bool found = false;
	if (p->value == key) {
		removeFirst();
		return;
	}
	while (p->next != nullptr)
	{
		if (p->next->value == key)
		{
			p = p->next->next;
			delete p->next;
			found = true;
			break;
		}
		p = p->next;
	}
	if (found)
		throw "value not found";
}



bool List2::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List2::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List2::firstElement()
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return ((int)head->value);
}

bool  List2::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}

void List2::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	// recover memory used by the first element
	delete p;
}

ostream& operator<<(ostream& os, const List2& L)
{
	List2::Link* p = L.head;
	for (p; p != nullptr; p = p->next)
	{
		os << p->value << " ";

	}
	return os;
}

istream& operator>>(istream& is, List2& L)
{
	int temp;
	is >> temp;
	L.add(temp);
	is >> temp;
	List2::Link* p = L.head;
	while (temp < p->value)
	{
		L.add(temp);
		is >> temp;
		p = L.head;
	}
	return is;
}

