/*
maor levi
328301981
sadna
targil#1-2
the program recieve from the user value of employee and check how get salary more high
or how donate less to the company
*/
#define crt_secure_no_warnings
#pragma warning (disable:4996)
#include "employ.h"
#include <iostream>
#include <string>
using namespace std;
void employ::setid(int num) {
	id = num;
}
void employ::setname(char arr[]) {
	strcpy_s(name, arr);
}
void employ::setwage_h(float num) {
	wage_h = num;
}
void employ::setwork_h(int num) {
	work_h=num;
}
void employ::setsum(float num) {
	sum = num;
}
void employ::setsalary(float num) {
	salary = num;
}
double employ:: total(float sum, int work, float wage) {
	double total = 0;
	double salary = 0;
	if (sum > 5000) {
		salary += ((sum - 5000) * 0.4);
		sum = 5000;

	}
	if ((sum > 4000)&& (sum <= 5000)) {
		salary += ((sum-4000) * 0.3);
		sum = 4000;
	}
	if ((sum > 2000) && (sum <= 4000)) {
		salary += ((sum -2000) * 0.2);
		sum = 2000;
	}
	if ((sum > 1000) && (sum <= 2000)) {
		salary += ((sum - 1000) * 0.15);
		sum = 1000;
	}
	if (sum <= 1000) {
		salary += (sum  * 0.1);
	}
	total = (work * wage) + salary;
	return total;
}
float employ::getsalary() {
	return salary;
}
int employ::getid(){
    return id;
}
char* employ:: getname(){
	return name;
}
float employ::getwage_h(){
	return wage_h;
}
int employ::getwork_h() {
	return work_h;
}
float employ::getsum(){
	return sum;
}
/*
enter details, to end enter 0:
111111111  doron  35  120  6000
222222222  tal  50  55  1400
444444444  levi  45  -4  100
ERROR
333333333  naomi  30  120  800
0
minimum collected: 333333333 naomi  800
highest  salary: 111111111 doron 5550

*/