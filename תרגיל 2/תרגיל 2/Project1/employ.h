#pragma once
#include "employ.cpp"
class employ
{
	int id;
	char name[21];
	float wage_h;//hour
	int work_h;//hour
	float sum;
	
public:
	double settotal(float sum, int work, float wage);
	void setid(int num);
	int getid(int num);
	void setname(char arr[]);
	char* getname(char arr[]);
	void setwage_h(float num);
	float getwage_h(float num);
	void setwork_h(int num);
	int getwork_h(int num);
	void setsum(float num);
	float getsum(float num);

};

