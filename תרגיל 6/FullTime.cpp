#include "FullTime.h"
#include <iostream>
using namespace std;

float FullTime::getSalaryPerYear()
{
	return salaryPerYear;
}

void FullTime::setSalaryPerYear(float NEWsalaryPerYear)
{
	salaryPerYear = NEWsalaryPerYear;
}

float FullTime::salary()
{
	if (salaryPerYear < 0)
	{
		throw "ERROR";//error if the salary is negative
	}
	else
		pay = salaryPerYear / 12.0;
	return pay;
}

ostream& operator<<(ostream& os, const FullTime& E)
{
	os << "Employee: " << E.name << endl;
	os << "Employee ID: " << E.id << endl;
	os << "Years Seniority: " << E.seniority << endl;
	os << "Salary per Month: " << E.pay << endl;
	return os;

}

istream& operator>>(istream& is, FullTime& E)
{
	cout << "Enter employee details:\n";
	is >> E.name;
	is >> E.id;

	is >> E.seniority;
	is >> E.salaryPerYear;

	E.pay = E.salary();
	if ((E.seniority<0 || E.id < 0))
		throw "ERROR";
	return is;
}
