#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(string N, int I, int S, float P)
{
	name = N;
	id = I;
	seniority = S;
	pay = P;
}

Employee::Employee()
{
	name;
	id = 0;
	seniority = 0;
	pay = 0;
}

Employee::Employee(const Employee& E)
{
	name = E.name;
	id = E.id;
	seniority = E.seniority;
	pay = E.pay;
}

string Employee::getname()
{
	return name;
}

int Employee::getid()
{
	
	return id;
}

int Employee::getseniority()
{
	return seniority;
}

float Employee::getpay()
{
	return pay;
}

void Employee::setname(string newName)
{
	name = newName;
}

void Employee::setid(int newID)
{
	if (id < 0)
		cout << "ERROR" << endl;
	else
		id = newID;
}

void Employee::setseniority(int newSENIORITY)
{
	if (seniority < 0)
		cout << "ERROR" << endl;
	else
		seniority = newSENIORITY;
}

void Employee::setpay(float newPAY)
{
	if (pay < 0)
		cout << "ERROR" << endl;
	else
		pay = newPAY;
}

float Employee::salaryAfterBonus()
{
	float bonos{};
	float temp = 0;

	if (seniority <= 5)
	{
		bonos = pay + 500;
	}
	else {
			temp = pay * 0.25;
			bonos = temp + pay;
		}
	return bonos;
}


ostream& operator<<(ostream& os, const Employee& E)
{
	
	os << "Employee: " << E.name << endl;
	os << "Employee ID:  " << E.id << endl;
	os << "Years Seniority: " << E.seniority << endl;
	return os;
}

istream& operator>>(istream& is, Employee& E)
{
	cout << "Enter employee details:\n";
	is >> E.name;
	
	is >> E.id;
	is >> E.seniority;
	
	if (E.seniority < 0|| E.id<0)
		throw "ERROR";

	return is;
}
