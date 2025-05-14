#pragma once
#include <iostream>
using namespace std;

class Employee
{
protected:
	string name;
	int id;
	int	seniority;
	float pay;
public:
	Employee(string N, int I, int S, float P); //constractor
	Employee();  //empty constractor
	Employee(const Employee& E); // copy constractor
	string getname();
	int getid();
	int getseniority();
	float getpay();
	void setname(string newName);
	void setid(int newID);
	void setseniority(int newSENIORITY);
	void setpay(float newPAY);
	float salaryAfterBonus();
	friend ostream& operator<<(ostream& os, const Employee& E);
	friend istream& operator>>(istream& is, Employee& E);
};