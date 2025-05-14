#include <iostream>
#include "employ.h"
#include <string>
using namespace std;
int main() {
	cout << "enter details, to end enter 0:" << endl;
	//employ highsalary, low;
	for (int i = 0;i < 8;i++) {

		double company;
		int taz, work;
		char name1[21];
		float wage, sum1;
		cin >> taz;
		if (taz == 0)
			break;
		else {
			employ e3;
			e3.setid(taz);
			cin >> name1;
			e3.setname(name1);
			cin >> wage;
			e3.setwage_h(wage);
			cin >> work;
			e3.setwork_h(work);
			cin >> sum1;
			e3.setsum(sum1);
			company = e3.settotal(sum1, work, wage);
			cout << company;
			cout << company;
			e3.setid(taz);
			cin >> name1;
			e3.setname(name1);
			cin >> wage;
			e3.setwage_h(wage);
			cin >> work;
			e3.setwork_h(work);
			cin >> sum1;
			e3.setsum(sum1);

		}

	}

	return 0;
}