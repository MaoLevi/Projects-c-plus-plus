/*
maorlevi
328301981
targil#1-1
the main recieve number and save him in class, in the main we do somthing like
add between two digits numbers or reduction digit number.

*/
#pragma once
class Rational
{
	int numerator;
	int denominator;
	void  reduction();
public:
	void setNumerator(int num);
	void setDenominator(int num);
	int getNumerator();
	int getDenominator();
	void print();
	bool equal(Rational rat2);
	Rational add(Rational r2);
};

