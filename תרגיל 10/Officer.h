#pragma once
#include "Soldier.h"
#include <string>
#include <iostream>
using namespace std;

class Officer :public Soldier
{
private:
	float SociometricScore;
public:
	Officer(const int, const string, const string, const int, const float);
	Officer();
	Officer(const Officer&);
	float getSociometricScore()const;
	bool Medal()const override;
	void print()override;
	string soldierType()const override;
	bool Combat()const { return false; }
};

