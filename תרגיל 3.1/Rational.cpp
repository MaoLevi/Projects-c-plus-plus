#include "Rational.h"
#include "Rational.h"
#include <iostream>
#include <math.h>
/*
maor levi
328301981
targil 3-1
sadna
the program recieve 2 digit number and make between them math operations
*/
using namespace std;
Rational::Rational(int const num, int const den) {
	numerator = num;
	if (den==0)
		denominator = 1;
	else
		denominator = den;
}
Rational::Rational(const Rational& v) {
	numerator = v.numerator;
	denominator = v.denominator;
}
Rational::Rational() {
	numerator = 1;
	denominator = 1;
}
Rational Rational::operator+(const Rational r2)
{
	Rational temp;
	temp.numerator = (numerator * r2.denominator) + (r2.numerator * denominator);//מבצע חיבור  רגיל מונה כפול מכנה ועוד מונה כפול מכנה
	temp.denominator = (denominator * r2.denominator);
	temp.reduce();//צמצום
	return Rational(temp);
}
Rational Rational::operator-(const Rational r2)
{
	Rational temp;
	temp.numerator = (numerator * r2.denominator) - (r2.numerator * denominator);//עושה מכנה משותף ואז מחסר
	temp.denominator = (denominator * r2.denominator);
	temp.reduce();
	return Rational(temp);
}
Rational Rational::operator/(const Rational r2)
{
	Rational temp;
	temp.numerator = numerator * r2.denominator;
	temp.denominator = denominator * r2.numerator;
	temp.reduce();
	return Rational(temp);
}
Rational Rational::operator*(const Rational r2)
{
	Rational temp;
	temp.numerator = numerator * r2.numerator;
	temp.denominator = denominator * r2.denominator;
	temp.reduce();
	return Rational(temp);
}
Rational Rational::operator++(int)
{
	Rational temp;//הוא מחזיר את הערך היישן אבל מקדם את הערך ב1
	temp.numerator = numerator;
	temp.denominator = denominator;
	numerator = numerator + denominator;
	return Rational(temp);
}
Rational& Rational::operator++()
{
	numerator = numerator + denominator;//מחזיר את הערך ועוד 1
	return (*this);
}
Rational Rational::operator--(int)
{
	Rational temp;//מחזיר את הערך הישן אבל מחסיר 1
	temp.numerator = numerator;
	temp.denominator = denominator;
	numerator = numerator - denominator;
	return Rational(temp);
}

Rational& Rational::operator--()
{
	numerator = numerator - denominator;//מחסיר ב1
	return (*this);
}

bool Rational::operator!=(const Rational &r2 )const
{
	return !(*this == r2);
}

bool Rational::operator==(const Rational r2) const
{
	Rational temp1 = r2;
	Rational temp2 = *this;
	temp1.reduce();
	temp2.reduce();
	if ((temp2.numerator == temp1.numerator) && (temp2.denominator == temp1.denominator))
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational r2) const
{
	Rational temp2 = *this;
	Rational temp1 = r2;
	temp1.numerator *= denominator;
	temp1.denominator *=denominator;
	temp2.numerator *= r2.denominator;
	temp2.denominator *= r2.denominator;
	if (temp2.numerator < temp1.numerator)
		return true;
	else
		return false;
}
bool Rational::operator>(const Rational r2) const
{
	Rational temp2 = *this;
	Rational temp1 = r2;
	temp1.numerator *= denominator;
	temp1.denominator *= denominator;
	temp2.numerator *= r2.denominator;
	temp2.denominator *=r2.denominator;
	if (temp2.numerator > temp1.numerator)
		return true;
	else
		return false;
}

bool Rational::operator<=(const Rational r2) const
{
	Rational temp2 = *this;
	Rational temp1 = r2;
	temp1.numerator *= denominator;
	temp1.denominator *= denominator;
	temp2.numerator *= r2.denominator;
	temp2.denominator *= r2.denominator;
	if (temp2.numerator <= temp1.numerator)
		return true;
	else
		return false;
	
}
bool Rational::operator>=(const Rational r2) const
{
	Rational temp2 = *this;
	Rational temp1 = r2;
	temp1.numerator *= denominator;
	temp1.denominator *= denominator;
	temp2.numerator *= r2.denominator;
	temp2.denominator *= r2.denominator;
	if (temp2.numerator >= temp1.numerator)
		return true;
	else
		return false;

}

void Rational::setNumerator(int const num)  {
	numerator = num;
}
void Rational::setDenominator(int  num) {
	if (num == 0)
		num = 1;
	else
		if (num < 0) {
			denominator = num * -1;
			numerator *= -1;
		}
		else
			denominator = num;
}
int Rational::getNumerator() const{
	return numerator;
}
int Rational::getDenominator() const {
	return denominator;
}

void Rational::print() const{
	if (denominator == 1) 
		cout << numerator;
	else
		cout << numerator << "/" << denominator;
}

void Rational::reduce() {

	for (int i = min(abs(numerator), denominator);i > 1;i--) {
		if ((numerator % i == 0) && (denominator % i == 0)) {
			numerator /= i;
			denominator /= i;
			return;
		}
	}
}
