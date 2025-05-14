#include "Book.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const bool Book::operator<=(const Book& SoE) const
{
	if (name_1 < SoE.name_1)
		return true;
	else if (name_1 > SoE.name_1)
		return false;
	else if (name_2 < SoE.name_2)
		return true;
	else if (name_2 > SoE.name_2)
		return false;
	else if (code < SoE.code)
		return true;
	else if (code > SoE.code)
		return false;
	return true;
}
istream& operator>>(istream& is, Book& get)
{
	is >> get.code >> get.name_1 >> get.name_2;
	return is;
}

Book::Book()
{
	code = 0;
	name_1 = " ";
	name_2 = " ";
}

Book::Book(int cod1, string& nam1, string& nam2)
{
	code = cod1;
	strcpy(name_1,nam1);
}



const bool Book::operator>=(const Book& BoE) const
{
	if (name_1 > BoE.name_1)
		return true;
	else if (name_1 < BoE.name_1)
		return false;
	else if (name_2 > BoE.name_2)
		return true;
	else if (name_2 < BoE.name_2)
		return false;
	else if (code > BoE.code)
		return true;
	else if (code < BoE.code)
		return false;
	return true;
}

const bool Book::operator==(const Book& E) const
{
	if (name_1 == E.name_1 && name_2 == E.name_2 && code == E.code)
		return true;
	return false;
}
const bool Book::operator>(const Book& B) const
{
	if (name_1 > B.name_1)
		return true;
	else if (name_1 < B.name_1)
		return false;
	else if (name_2 > B.name_2)
		return true;
	else if (name_2 < B.name_2)
		return false;
	else if (code > B.code)
		return true;
	else if (code < B.code)
		return false;
	return false;
}

const bool Book::operator!=(const Book& N) const
{
	if (name_1 == N.name_1 && name_2 == N.name_2 && code == N.code)
		return false;
	return true;
}

ostream& operator<<(ostream& os, const Book& print)
{
	os << print.code << " " << print.name_1 << " " << print.name_2 << endl;
	return os;
}

const bool Book::operator<(const Book& S) const
{
	if (name_1 < S.name_1)
		return true;
	else if (name_1 > S.name_1)
		return false;
	else if (name_2 < S.name_2)
		return true;
	else if (name_2 > S.name_2)
		return false;
	else if (code < S.code)
		return true;
	else if (code > S.code)
		return false;
	return false;
}