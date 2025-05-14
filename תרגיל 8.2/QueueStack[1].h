#pragma once
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;


class QueueStack:public Queue
{
protected:
	Stack* data;
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;

};

