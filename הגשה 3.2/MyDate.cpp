#include "MyDate.h"
#include <iostream>
using namespace std;
MyDate::MyDate()
{
	day = 1;
	month = 1;
	year = 1920;
}

MyDate::MyDate(int d, int m, int y)
{
	if (d > 30 || d < 1) {
		cout << "Error day" << endl;
		day = 1;
	}
	else
		day = d;
	if (m > 12 || m < 1) {
		cout << "Error month" << endl;
		month = 1;
	}
	else
		month = m;
	if (y < 1920) {
		cout << "Error year" << endl;
		year = 1920;
	}
	else
		year = y;
	
}
MyDate::MyDate(const MyDate& v)
{
	day = v.day;
	month = v.month;
	year = v.year;
}

void MyDate::setDate(int const d, int const m, int const y)
{
	if (d <= 30 && d >= 1) {
		if (m <= 12 && m >= 1) {
			if (y >= 1920) {
				day = d;
				month = m;
				year = y;
			}
		}
	}
}

void MyDate::print() const
{
	cout << day << '/' << month << '/' << year;
	
}

MyDate MyDate::operator=(const MyDate& da)
{
	day = da.day;
	month = da.month;
	year = da.year;
	return MyDate(*this);
}
MyDate MyDate::operator++(int)
{
	MyDate temp=*this;

	if (day == 30) {
		if (month == 12) {
			month = 1;
			year += 1;
		}
		else
			month += 1;
		day = 1;
	}
	else
		day += 1;
	return MyDate(temp);
}

MyDate& MyDate::operator++()
{
	if (day == 30) {
		if (month == 12) {
			month = 1;
			year += 1;
		}
		else
			month += 1;
		day = 1;
	}
	else
		day += 1;
	return *this;
}

bool MyDate::operator<(MyDate const da) const
{
	if (year < da.year)
		return true;
	else {
		if (year == da.year) {
			if (month < da.month)
				return true;
			else
				if (month == da.month) {
					if (day < da.day)
						return true;
					else
						if (day == da.day)
							return false;
				}
				else
					return false;




		}
		else
			return false;
	}
	return false;
}
bool MyDate::operator>(MyDate const da) const
{
	if (year > da.year)
		return true;
	else {
		if (year == da.year) {
			if (month > da.month)
				return true;
			else
				if (month == da.month) {
					if (day > da.day)
						return true;
					else
						if (day == da.day)
							return false;
				}
				else
					return false;



		}
		else
			return false;
	}
	return false;
}

bool MyDate::operator==(MyDate const date) const
{
	if (year == date.year) {
		if (month == date.month) {
			if (day == date.day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
