#include "Clock.h"

Clock::Clock()
{
	hour = 0;
	minute = 0;
	second = 0;
}
void Clock::sets(int sr)
{
	if (sr < 0) {
		check(1);
	}
	if (sr > 60) {
		check(2);
	}
	second = sr;
}
void Clock::check(int h)
{
	if (h==1) 
		throw "Invalid time - negative number of seconds.";
	if (h==2) 
		throw "Invalid time - more than 60 seconds.";
	
	if (h==3)
		throw "Invalid time - negative number of minutes.";
	if (h==4) 
		throw "Invalid time - more than 60 minutes.";

	if (h==5)
		throw "Invalid time - negative number of hours.";
	
	if (h==6) 
		throw "Invalid time - more than 24 hours.";
}



Clock Clock::operator+=(int s)
{
	int ch = s + second;
	if (ch >= 60) {
		minute += ch / 60;
		second = (s + second) % 60;
	}
	else
		second += s;
	if (minute >= 60) {
		hour += minute / 60;
		minute = minute % 60;
	}
	return Clock(*this);
}
ostream& operator<<(ostream& os, const Clock& r)
{
	if (r.hour < 10)
		os << '0' << r.hour << ":";
	else
		os << r.hour << ": ";
	if (r.minute < 10)
		os << '0' << r.minute << ":";
	else
		os << r.minute << ":";
	if (r.second < 10)
		os << '0' << r.second;
	else
		os << r.second;
	
	return os;
}
istream& operator>>(istream& is, Clock& r) {

	if (r.second < 0) {
		r.hour>>00;
		r.minute>> 00;
		r.second>> 0;
		throw "Invalid time - negative number of seconds.\n";
	}
	if (r.second > 60) {
		r.hour >> 00;
		r.minute >> 00;
		r.second>> 00;
		throw "Invalid time - more than 60 seconds\n.";
	}
	if (r.minute < 0) {
		r.hour >> 00;
		r.minute>>00;
		r.second >> 00;
		throw "Invalid time - negative number of minutes.\n";
	}
	if (r.minute > 60) {
		r.hour >> 00;
		r.minute >> 00;
		r.second >> 00;
		throw "Invalid time - more than 60 minutes.\n";
	}
	if (r.hour < 0) {
		r.hour >> 00;
		r.minute >> 00;
		r.second >> 00;
		throw "Invalid time - negative number of hours.\n";
	}
	if (r.hour > 24) {
		r.hour >> 00;
		r.minute >> 00;
		r.second >> 00;
		throw "Invalid time - more than 24 hours.\n";
	}
	throw "Wrong time format.";
	return is;
}
Clock::Clock(int h, int m, int s)
{
	if (s < 0) {
		
		hour = 0;
		minute = 0;
		second = 0;
		check(1);
	}
	if (s > 60) {
		hour = 0;
		minute = 0;
		second = 0;
		check(2);
	}
	if (m < 0) {
		hour = 0;
		minute = 0;
		second = 0;
		check(3);
	}
	if (m > 60) {
		hour = 0;
		minute = 0;
		second = 0;
		check(4);
	}
	if (h < 0) {
		hour = 0;
		minute = 0;
		second = 0;
		check(5);
	}
	if (h > 24) {
		hour = 0;
		minute = 0;
		second = 0;
		check(6);
	}
	hour = h;
	minute = m;
	second = s;
}

int Clock::geth()
{
	return hour;
}
int Clock::getm()
{
	return minute;
}

void Clock::seth(int h)
{
	if ( h< 0) {
		check(5);
	}
	if (h > 24) {
		check(6);
	}
	hour = h;
}
void Clock::setm(int m) {
	if (m < 0) {
	check(3);
	}
	if (m > 60) {
	check(4);
	}
	minute = m;
}

int Clock::gets()
{
	return second;
}