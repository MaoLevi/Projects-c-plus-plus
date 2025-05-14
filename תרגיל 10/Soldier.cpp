#include "Soldier.h"
#include <iostream>
using namespace std;

Soldier::Soldier(int id, string& name, string& Last, int num)
{
	Id = id;
	FirstName = name;
	Last_Name = Last;
	numMission = num;
}

int Soldier::getId()const
{
	return Id;
}

string Soldier::getFirstName()const
{
	return FirstName;
}

string Soldier::getLastName()const
{
	return Last_Name;
}

int Soldier::getnumMission()const
{
	return numMission;
}
