#include "employ.h"
#include <iostream>
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
	work_h = num;
}
void employ::setsum(float num) {
	sum = num;
}
double employ:: settotal(float sum, int work, float wage) {
	double total = 0;
	double salary = 0;
	if (sum > 5000) {
		salary = ((sum - 5000) * 0.4);
		sum = 5000;

	}
	if ((sum > 4000) && (sum <= 5000)) {
		salary = ((sum - 4000) * 0.3);
		sum = 4000;
	}
	if ((sum > 2000) && (sum <= 4000)) {
		salary = ((sum - 2000) * 0.2);
		sum = 2000;
	}
	if ((sum > 1000) && (sum <= 2000)) {
		salary = ((sum - 1000) * 0.15);
		sum = 1000;
	}
	if (sum <= 1000) {
		salary = (sum * 0.1);
	}
	total = (work * wage) + salary;
	return total;
}

int employ::getid(int num) {
	return id;
}
char* employ::getname(char arr[]) {
	return name;
}
float employ::getwage_h(float num) {
	return wage_h;
}
int employ::getwork_h(int num) {
	return work_h;
}
float employ::getsum(float sum) {
	return sum;
}
