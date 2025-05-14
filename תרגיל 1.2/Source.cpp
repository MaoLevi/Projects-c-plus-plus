#include "Polygon.h"
#include "Point.h"
#include <iostream>
using namespace std;
/*
maor levi
328301981
sadna
targil#2-1
the program recieve from the user value of point and create strangle 
the program colculte the value of the scope and othe thing
at the begining you ask why we didnt need function destory,the answer is
because we didnt need to destory nothing we have just a point not arr.
the answer of the second question is because we use in the set function of the point
*/
int main() {
	int size, x, y;
	char ch;
	cout << "enter number of sides:" << endl;
	cin >> size;
	Polygon ribbed1 = Polygon(size);
	cout << "enter the point values: " << endl;
	for (int i = 0;i < size;i++) {
		cin >> ch >> x >> ch >> y >> ch;
		
		Point a;
		a.setPointx(x);
		a.setPointy(y);

		ribbed1.addPoint(a, i);
	}
	cout << "enter number of sides:" << endl;
	cin >> size;
	Polygon ribbed2 = Polygon(size);
	cout << "enter the point values: " << endl;
	for (int i = 0;i < size;i++) {
		cin >> ch >> x >> ch >> y >> ch;
		Point a(x, y);
		ribbed2.addPoint(a, i);
	}
	if (ribbed1.check(ribbed2) == true) {
		cout << "equal\n" << "perimeter: " << round(ribbed1.scope()) << endl;
	}
	else {
		cout << "not equal" << endl;
		cout << "perimeter: " << round(ribbed1.scope()) << endl;
		cout << "perimeter: " << round(ribbed2.scope()) << endl;
	}
	return 0;
}
/*
enter number of sides:
3
in one parameter constructor
enter the point values:
(10,10) (10,14) (13,10)
enter number of sides:
3
in one parameter constructor
enter the point values:
(13,10) (10,10) (10,14)
in copy constructor
in destructor
equal
perimeter: 12
in destructor
in destructor

*/