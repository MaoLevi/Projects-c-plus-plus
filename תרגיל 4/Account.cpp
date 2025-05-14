#include "Account.h"
#include <string>
#include <iostream>
using namespace std;
int Account::sumW = 0;
int Account::sumD = 0;
Account::Account() {
	accountNumber = 0;
	code = 0;
	balance = 0;
	string email;
}

Account::Account(int a, int c, int b, string e)
{
	if ((c < 1000)||(c>=10000))
		throw "ERROR: code must be of 4 digits\n";
	else {
		size_t k = e.find('@');
		if (k == -1)
			throw "ERROR: email must contain @!\n";
		else {
			string str1 = ".com";
			string str2 = ".co.il";
			size_t f1 = e.find(str1);
			size_t f2 = e.find(str2);
			if ((f1==-1) && (f2 == -1))
				throw "ERROR: email must end at.com or .co.il!\n";
			else
			{
				email = e;
				accountNumber = a;
				balance = b;
				code = c;
			}
		}
	}
}

int Account::getAccountNumber()
{
	return accountNumber;
}

int Account::getCode()
{
	return code;
}

int Account::getBalance()
{
	return balance;
}

string Account::getemail()
{
	return string(email);
}

void Account::withdraw(int nis)
{
	if ((balance - nis) < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!\n";
	if (nis > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	balance -= nis;
	sumW += nis;
}

void Account::deposit(int c)
{
	if (c > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!\n";
	else
	{
		balance += c;
		sumD += c;
	}

}


 int& Account::getSumWithdraw()
{
	return sumW;
}

int Account::getSumDeposit()
{
	return sumD;
}

istream& operator>>(istream& is, Account& in)
{
	is >> in.accountNumber;
	is >> in.code;
	is >> in.email;
	if (in.code < 1000||in.code>=10000)
		throw "ERROR: code must be of 4 digits\n";
	else {
		size_t k = in.email.find('@');
		if (k == -1)
			throw "ERROR: email must contain @!\n";
		else {
			string str1 = ".com";
			string str2 = ".co.il";
			size_t f1 = in.email.find(str1);
			size_t f2 = in.email.find(str2);
			if ((f1 == -1) && (f2 == -1))
				throw "ERROR: email must end at.com or .co.il!\n";
		}
	}
	// TODO: insert return statement here
}
