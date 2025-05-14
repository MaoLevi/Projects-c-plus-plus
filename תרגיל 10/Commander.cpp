#include "Commander.h"
#include "PrivateSoldier.h"
#include <iostream>
using namespace std;

Commander::Commander(int id, string firatname, string lastname, int missions, int* grades, bool combat) :PrivateSoldier()
{
	Combat = combat;

}
Commander::Commander() :PrivateSoldier()
{
	Combat = 0;
}

Commander::~Commander()
{
	if (MissionGrade)
	{
		delete[] MissionGrade;
		MissionGrade = NULL;
	}
}

Commander::Commander(const Commander& c) :PrivateSoldier(c)
{
	Combat = c.Combat;
}

int Commander::getIscombat()const
{
	return Combat;
}

bool Commander::Medal()const
{

	double sum = 0;
	for (int i = 0; i < numMission; i++)
	{
		sum += MissionGrade[i];
	}
	double avarage = sum / numMission;
	if ((numMission >= 7) && (avarage > 90) && (Combat))
	{
		return true;
	}
	else
		return false;
}


void Commander::print()
{
	cout << "IS COMBAT:";
	if (Combat)
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}

string Commander::soldierType()const
{
	return "Commander";
}

bool Commander::IsCOmbat() const
{
	if (Combat)
	{
		return true;
	}
	else
		return false;
}

