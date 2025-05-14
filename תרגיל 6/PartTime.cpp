#include"Employee.h"
#include "PartTime.h"
#include <iostream>
using namespace std;


int PartTime::gethoursOfWork()
{
	return hoursOfWork;
}

float PartTime::getpayPerHour()
{
	return payPerHour;
}

void PartTime::sethoursOfWork(int NEWhoursOfWork)
{
	hoursOfWork = NEWhoursOfWork;
}

void PartTime::setpayPerHour(float NEWpayPerHour)
{
	payPerHour = NEWpayPerHour;
}

float PartTime::salary()
{
	if (hoursOfWork < 0 || payPerHour < 0)
	{
		throw"ERROR";
	}
	else
		pay = hoursOfWork * payPerHour;
	return pay;
}

ostream& operator<<(ostream& os, const PartTime& E)
{
	os << "Employee: ";
	os << E.name << endl;
	os << "Employee ID: " << E.id << endl;
	os << "Years Seniority: " << E.seniority << endl;
	os << "Hours: " << E.hoursOfWork << endl;
	os << "Salary per Month: " << E.pay << endl;

	return os;
}

istream& operator>>(istream& is, PartTime& E)
{
	cout << "Enter employee details:\n";
	is >> E.name;
	is >> E.id;
	is >> E.seniority;
	is >> E.hoursOfWork;
	is >> E.payPerHour;
	E.pay = E.salary();
	if (E.seniority < 0 || E.id < 0)
		throw "ERROR";
	return is;
}
