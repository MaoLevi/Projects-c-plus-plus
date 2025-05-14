/*
maorlevi
328301981
targil#1-1
the main recieve number and save him in class, in the main we do somthing like
add between two digits numbers or reduction digit number.

*/
#include "Rational.h"
#include <iostream>
#include <math.h>
using namespace std;
void Rational::setNumerator(int num) {
	numerator = num;
}
void Rational::setDenominator(int num) {
	if (num == 0)
		denominator = 1;
	else
		if (num < 0) {
			denominator = num * -1;
			numerator *= -1;
		}
		else
			denominator = num;
}
int Rational::getNumerator() {
	return numerator;
}
int Rational::getDenominator() {
	return denominator;
}

void Rational::print() {
	cout << numerator << "/" << denominator;
}
bool Rational::equal(Rational rat2) {
	if ((numerator == rat2.numerator) && (denominator == rat2.denominator))
		return true;
	else
		return false;
}
void Rational::reduction() {

	for (int i = min(abs(numerator), denominator);i > 1;i--) {
		if ((numerator % i == 0) && (denominator % i == 0)) {
			numerator /= i;
			denominator /= i;
			return;
		}
	}
}
Rational Rational::add(Rational r2) {
	Rational r3;
	r3.numerator = (numerator * r2.denominator) + (r2.numerator * denominator);
	r3.denominator = (denominator * r2.denominator);
	if (r3.numerator == 0) {
		r3.denominator = 1;
	}
	r3.reduction();
	return r3;
}
