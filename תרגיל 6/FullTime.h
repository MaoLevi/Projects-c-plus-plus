#include"Employee.h"
#include <iostream>
using namespace std;

class FullTime : public Employee
{
private:
	float salaryPerYear;
public:
	FullTime(float Y) : Employee(), salaryPerYear(Y) {
		Employee* pay;
		pay = new FullTime();
		((FullTime*)pay)->salary();

		salaryPerYear = Y;
	};
	FullTime() :Employee(), salaryPerYear(0) {}
	FullTime(const FullTime& E) :Employee(), salaryPerYear() { salaryPerYear = E.salaryPerYear; }
	float getSalaryPerYear();
	void setSalaryPerYear(float salaryPerYear);
	float salary();
	friend ostream& operator<<(ostream& os, const FullTime& E);
	friend istream& operator>>(istream& is, FullTime& E);
};

