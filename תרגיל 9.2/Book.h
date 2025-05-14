#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
	string name_1;
	string name_2;
	int code;
public:
	Book();
	Book(int cod1,string& nam1,string& nam2);
	const bool operator>=(const Book&)const;
	const bool operator>(const Book&)const;
	const bool operator<=(const Book&)const;
	const bool operator!=(const Book&)const;
	const bool operator==(const Book&)const;
	const bool operator<(const Book&)const;
	friend istream& operator>>(istream& is, Book& in);
	friend ostream& operator<<(ostream& os, const Book& out);
};

