/*
maor levi
328301981
sadna
targil#1-2
the program recieve from the user value of employee and check how get salary more high
or how donate less to the company
*/
#include <iostream>
#include "employ.h"
#include <string>
using namespace std;
int main() {
	cout << "enter details, to end enter 0:" << endl;
	employ high, low;
	for (int i = 0;i<1000;i++) {
		double company;
		int taz, work;
		char name1[21];
		float wage, sum1;
		cin >> taz;
		if (taz == 0)
			break;
		else {
			employ e3;
			cin >> name1;
			cin >> wage;
			cin >> work;
			cin >> sum1;
			if ((work < 0) || (sum1 < 0) || (wage < 0)) {
				cout << "ERROR" << endl;
				i -= 1;
			}
			else {
				e3.setname(name1);
				e3.setid(taz);
				e3.setwage_h(wage);
				e3.setwork_h(work);
				e3.setsum(sum1);
				company = e3.total(sum1, work, wage);
				e3.setsalary(company);
				if (i == 0) {
					low = e3;
					high = e3;
				}
				else {
					if (low.getsum() > sum1) {
						low = e3;
					}
					if (high.getsalary() < e3.getsalary()) {
						high = e3;
					}
				}
			}
		}

	}
	cout << "minimum collected: " << low.getid() << " " << low.getname() << " " << low.getsum() << endl;
	cout << "highest  salary: " << high.getid() << " " << high.getname() << " " << high.getsalary() << endl;
	return 0;
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