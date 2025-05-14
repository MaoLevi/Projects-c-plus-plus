#include "Family.h"
#define crt_secure_no_warnings
#pragma warning (disable:4996)
#include <cstring>

using namespace std;
int Family::getnumfamily()
{
	return numfamily;
}
Family::Family()
{
	numfamily = 0;
	strcpy(lastname,"");
	number = 0;
	phonenumber = 0;
	activity = 0;
}

Family::Family(int numf, char lastm[20], int numb, int phone,int lis)
{
	numfamily = numf;
	strcpy(lastname,lastm);
	number = numb;
    phonenumber=phone;
	activity = lis;
}

short Family::getactivity()
{
	return activity;
}


void Family::setactivity(int activ)
{
	activity += activ;
}

Family Family::operator=(const Family& vec)
{
	numfamily = vec.numfamily;
	strcpy(lastname, vec.lastname);
	number = vec.number;
	phonenumber = vec.phonenumber;
	return *this;
}

ostream& operator<<(ostream& os, const Family& print)
{
	os << "family name: " << print.lastname << endl;
	os << "number of persons: " << print.number << endl;
	os << "phone number: " << print.phonenumber << endl;
	return os;
}
