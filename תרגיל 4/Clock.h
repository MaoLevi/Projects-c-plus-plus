#pragma once
#include <iostream>
using namespace std;
class Clock
{
	int hour;
	int minute;
	int second;
public:
	Clock();
	Clock(int h,int m,int s);
	int geth();
	int getm();
	int gets();
	void seth(int h);
	void setm(int m);
	void sets(int sr);
	void check(int h);
	Clock operator+=(int s);
	friend ostream& operator<<(ostream& os, const Clock& r);
	friend istream& operator>>(istream& is, Clock& in);

};

