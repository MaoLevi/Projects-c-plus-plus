#pragma once

class MyDate
{
	int day;
	int month;
	int year;
public:
	
	MyDate();
	MyDate(int, int, int);
	MyDate(const MyDate&);
	void setDate(int, int, int);
	void print()const;
	MyDate operator=(const MyDate&);
	MyDate operator++(int);
	MyDate &operator++();
	bool operator<(MyDate const) const;
	bool operator>(MyDate const) const;
	bool operator==(MyDate const) const;
};

