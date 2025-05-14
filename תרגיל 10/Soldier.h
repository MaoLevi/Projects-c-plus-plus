#pragma once
#include <string>
#include <iostream>
using namespace std;
class Soldier
{
protected:
	int Id;
	string FirstName;
	string Last_Name;
	int numMission;
public:
	Soldier(int id, string& name, string& Last, int num);
	Soldier() : Id(0), FirstName(" "), Last_Name(" "), numMission(0) {}
	string getFirstName()const;
	string getLastName()const;
	int getnumMission()const;
	virtual bool Medal()const = 0;
	virtual void print() = 0;
	virtual string soldierType()const = 0;
	int getId()const;
};


