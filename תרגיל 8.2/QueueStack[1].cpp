#include "QueueStack.h"
#include "Stack.h"
#include <iostream>
using namespace std;

QueueStack::QueueStack()
{
	data = new Stack();
}

void QueueStack::clear()
{
	delete data;
}

int QueueStack::dequeue()
{
	if (this->isEmpty())
		return NULL;
	else {
		Stack temp;
		int y= this->size;
		for (int i = 0; i <y; i++)
			temp.push(this->pop());
		int x = temp.pop();
		y= temp.getSize();
		for (int i = 0; i <y;  i++)
			this->push(temp.pop());
		temp.clear();
		return x;
	}
}

void QueueStack::enqueue(int value)
{
	
	
this->push(value);

}

int QueueStack::front()
{
	
	Stack temp;
	int y= this->size;
	for (int i = 0; i <y;  i++)
		temp.push(this->pop());
	int x = temp.top();
	y = temp.getSize();
	for (int i = 0; i < y; i++)
		this->push(temp.pop());
	
	return x;
}

bool QueueStack::isEmpty() const
{

	return (this->size==0);
}
