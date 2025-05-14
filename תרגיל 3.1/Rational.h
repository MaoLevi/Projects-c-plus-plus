/*
maor levi
328301981
targil 3-1
sadna
the program recieve 2 digit number and make between them math operations
*/
#pragma once
class Rational
{
	int numerator;
	int denominator;
	void  reduce();
public:
	Rational(int, int);
	Rational(const Rational& );
	Rational();
	Rational operator+ (const Rational);
	Rational operator- (const Rational);
	Rational operator/ (const Rational);
	Rational operator* (const Rational);
	Rational operator++ (int );
	Rational& operator++ ( );
	Rational operator-- (int);
	Rational& operator-- ();
	bool operator!= (const Rational& ) const;
	bool operator== (const Rational ) const;
	bool operator< (const Rational) const;
	bool operator> (const Rational) const;
	bool operator>= (const Rational) const;
	bool operator<= (const Rational) const;
	void setNumerator(int num);
	void setDenominator(int num) ;
	int getNumerator() const;
	int getDenominator() const;
	void print() const;
	
};

