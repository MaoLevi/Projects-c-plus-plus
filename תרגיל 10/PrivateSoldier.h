#pragma once
#include "Soldier.h"
#include <string>
#include <iostream>
using namespace std;
class PrivateSoldier :public Soldier
{
protected:
	int* MissionGrade;
public:
	PrivateSoldier(int, string, string, int, int*);
	PrivateSoldier();
	PrivateSoldier(const PrivateSoldier&);
	PrivateSoldier(PrivateSoldier&&);
	int getMissionGrade()const;
	bool Medal() const override;
	virtual void print() override;
	string soldierType()const override;

};

