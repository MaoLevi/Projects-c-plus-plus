
#include "PrivateSoldier.h"
#include "Soldier.h"
#include <string>



PrivateSoldier::PrivateSoldier(int id, string firstname, string lastname, int missions, int* grade)
{
	if (grade)
	{
		grade = new int[numMission];
		for (int i = 0; i < numMission; i++)
		{
			MissionGrade[i] = grade[i];
		}
	}
	else
		grade = NULL;
}

PrivateSoldier::PrivateSoldier() :Soldier()
{
	MissionGrade = NULL;
}

PrivateSoldier::PrivateSoldier(const PrivateSoldier& a)
{
	for (int i = 0; i < numMission; i++)
	{
		MissionGrade[i] = a.MissionGrade[i];
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& a)
{
	MissionGrade = a.MissionGrade;
	a.MissionGrade = NULL;
}



int PrivateSoldier::getMissionGrade()const
{
	return *MissionGrade;
}

bool PrivateSoldier::Medal()const
{
	double sum = 0;
	for (int i = 0; i < numMission; i++)
	{
		sum += MissionGrade[i];
	}
	double avarage = sum / numMission;
	if (numMission >= 10 && avarage > 95)
	{
		return true;
	}
	else
		return false;
}

void PrivateSoldier::print()
{
	cout << "ID:" << Id << endl;
	cout << "FirstName:" << FirstName << endl;
	cout << "Last_Name:" << Last_Name << endl;
	if (numMission > 0)
	{
		cout << "Number of Missions: " << numMission << endl;
		cout << "Mission Grades:" << endl;
		for (int i = 0; i < numMission; i++)
		{
			cout << "Missio" << i + 1 << ":" << MissionGrade[i] << " " << endl;
		}
	}
	else
		cout << "Number of Missions: N/A" << endl;
}

string PrivateSoldier::soldierType()const
{
	return "PrivateSoldier";
}
