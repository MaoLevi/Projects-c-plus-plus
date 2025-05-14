#pragma once
#include"Employee.h"
#include <iostream>
using namespace std;

class PartTime : public Employee
{
private:
	int	hoursOfWork;
	float payPerHour;
public:
	PartTime(int H, float Y) : Employee(), hoursOfWork(H), payPerHour(Y) {
		Employee* pay;
		pay = new PartTime();
		((PartTime*)pay)->salary();

		hoursOfWork = H;
		payPerHour = Y;
	}
	PartTime() :Employee(), hoursOfWork(0), payPerHour(0) {}
	PartTime(const PartTime& E) :Employee(), hoursOfWork(E.hoursOfWork), payPerHour(E.payPerHour) {
		hoursOfWork = E.hoursOfWork;
		payPerHour = E.payPerHour;
	}

	int gethoursOfWork();
	float getpayPerHour();
	void sethoursOfWork(int NEWhoursOfWork);
	void setpayPerHour(float NEWpayPerHour);
	float salary();
	friend ostream& operator<<(ostream& os, const PartTime& E);
	friend istream& operator>>(istream& is, PartTime& E);
};


