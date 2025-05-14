#pragma once
#include "PrivateSoldier.h"
#include <string>
#include <iostream>
using namespace std;
class Commander :public PrivateSoldier
{
private:
	bool Combat;
public:
	Commander(int, string, string, int, int*, bool);
	Commander();
	~Commander();
	Commander(const Commander& c);
	int getIscombat()const;
	virtual bool Medal()const override;
	virtual void print() override;
	string soldierType()const override;
	bool IsCOmbat()const;

};


