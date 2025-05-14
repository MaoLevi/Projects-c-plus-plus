#pragma once
#include <iostream>
using namespace std;
class Family
{

	unsigned int numfamily;
	char lastname[20];
	unsigned int number;
	unsigned int phonenumber;
	unsigned short activity;
public:
	int getnumfamily();
	Family();
	Family(int numf,char lastm[20],int numb,int phone,int lis);
	friend ostream& operator <<(ostream& os,const Family & print);
	short getactivity();
	void setactivity(int activ);
	Family operator=(const Family& vec);
};

