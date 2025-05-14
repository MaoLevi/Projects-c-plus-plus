#pragma once

#include <string>
#include <iostream>  
using namespace std;
class Account
{
	int accountNumber;
	int code;
	int balance;
	string email;
public:
	Account();
	Account(int, int, int, string);
	int getAccountNumber();
	int getCode();
	int getBalance();
	string getemail();
	friend istream& operator>>(istream& is, Account& in);
	void withdraw(int nis);
	void deposit(int);
	static int sumW;
	static int sumD;
	
	int& getSumWithdraw();
	int getSumDeposit();
};

