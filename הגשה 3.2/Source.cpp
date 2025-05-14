/*
maor levi
328301981
targil 3-2
sadna
the program recieve date and make coculate 
*/
#include <iostream>
using namespace std;
#include"MyDate.h"


enum OPERATOR {
	EXIT, Setdate, ADD_PRE, ADD_POST, CHANGE,GREATER, LESS_THAN, EQUAL
};

void print(MyDate rat1, MyDate rat2, const char* op) {
	rat1.print();
	cout << " " << op << " ";
	rat2.print();
	cout <<": ";
}

int main()
{
	
	int day, month, year;
	char junk;
	int op;
	cout << "Enter a date" << endl;
	cin >> day >> junk >> month >> junk >> year;//קלט מהמשתמש
	MyDate r2;
	MyDate r1(day, month, year);
	r1.print();//הדפסת הערך שהוצב בתוך התאריך
	cout << endl;
	cout << "Enter a code" << endl;
	cin >> op;
	
	while (op != EXIT) {
		
		switch (op) {
		case Setdate: 
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			r1.setDate(day, month, year);
			r1.print();
			break;
		
		case ADD_PRE:// הדפסת אופרטור ++ תחילי על התאריך
			r2 = ++r1;
			r2.print();
			cout << endl;
			r1.print();
			break;
		case ADD_POST:// הדפסת אופרטור ++ סופי  על התאריך
			r1.print();
			cout << endl;
			r1++;
			r1.print();
			break;
		case CHANGE:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			r2.setDate(day, month, year);
			r2.print();
			r1 = r2;
			break;
		case GREATER:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			r2.setDate(day, month, year);
			print(r1, r2, ">");
			if (r1 > r2)
				cout << "true\n";
			else cout << "false\n";
			break;
		case LESS_THAN:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			r2.setDate(day, month, year);
			print(r1, r2, "<");
			if (r1 < r2)
				cout << "true\n";
			else cout << "false\n";
			break;
		case EQUAL:
			cout << "Enter a date" << endl;
			cin >> day >> junk >> month >> junk >> year;
			r2.setDate(day, month, year);
			print(r1, r2, "==");
			if (r1 == r2)
				cout << "true\n";
			else cout << "false\n";
			break;
		}
		cout << endl;
		cout << "Enter a code" << endl;
		cin >> op;
	}

	return 0;
}
/*
Enter a date
-5/1/2012
Error day
1/1/2012
Enter a code
1
Enter a date
5/7/2010
5/7/2010
Enter a code
2
6/7/2010
6/7/2010
Enter a code
3
6/7/2010
7/7/2010
Enter a code
4
Enter a date
14/7/2010
14/7/2010
Enter a code
5
Enter a date
14/7/2010
14/7/2010 > 14/7/2010 : false
Enter a code
7
Enter a date
14/7/2010
14/7/2010 == 14/7/2010 : true
Enter a code
0
*/