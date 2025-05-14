#include "Officer.h"
#include <iostream>
using namespace std;


Officer::Officer(const int id, const string firstname, const string lastname, const int missions, const float Sociometric) :Soldier()
{
	SociometricScore = Sociometric;
}

Officer::Officer() :Soldier()
{
	SociometricScore = 0;
}

Officer::Officer(const Officer& a) :Soldier()
{
	SociometricScore = a.SociometricScore;
}

float Officer::getSociometricScore()const
{
	return SociometricScore;
}



bool Officer::Medal()const
{
	if ((numMission > 2) && (SociometricScore >= 92))
	{
		return true;
	}
	else
		return false;
}

void Officer::print()
{
	cout << soldierType() << endl;
	cout << "ID:" << Id << endl;
	cout << "FirstName:" << FirstName << endl;
	cout << "Last_Name:" << Last_Name << endl;
	cout << "numMission:" << numMission << endl;
	cout << "SociometricScore:" << SociometricScore << endl;
}

string Officer::soldierType()const
{
	return "Officer";
}
