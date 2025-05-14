/*
maorlevi
328301981
sadna 11
*/
#include "Family.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;
enum { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };
enum ACTIVITY {
	NONE, //  טרם בחר חוג
	SWIMMING,          // שחיה 
	GYMNATSTICS,         // התעמלות קרקע
	DANCE = 4,     // מחול
	ART = 8,    // אומנות
	SELF_DEFENSE = 16, // הגנה עצמית
	MUSIC = 32, // מוסיקה
	DRAMA = 64, // דרמה
	BASKETBALL = 128 // כדור סל
};

void  setFile(fstream& file) {
	Family ch;//create empty family and restart the txt
	for (int i = 0;i < 100;i++) {
		file.write((char*)&ch, sizeof(Family));
	}
}

void add(fstream& file) {
	Family check;
	unsigned int numfamily1;
	char lastname1[20];
	unsigned int number1;
	unsigned int phonenumber1;
	cout << "enter the family's:  id, name, amount of people and a phone number: ";
	cin >> numfamily1;
	cin >> lastname1;
	cin >> number1;
	cin >> phonenumber1;
	if (numfamily1 > 100) {
		throw  "ERROR: Invalid family number";
	}
	else {
		file.seekg(sizeof(Family) * (numfamily1 - 1));
		file.read((char*)&check, sizeof(Family));
		if (check.getnumfamily() != 0) {
			throw  "ERROR: Family is already in the file";
		}
		else {
			Family temp(numfamily1, lastname1, number1, phonenumber1,0);
			file.seekp(sizeof(Family) * (numfamily1 - 1));
			file.write((char*)&temp, sizeof(Family));
		}
	}
	file.clear();
}
void del(fstream& file, int numfamily1) {
	if(numfamily1>100)
		throw  "ERROR: Invalid family number";
	else {
		Family check;
		file.seekg(sizeof(Family) * (numfamily1 - 1));
		file.read((char*)&check, sizeof(Family));
		if (check.getnumfamily() == 0) {
			throw  "ERROR: Family is not in the file";
		}
		else
		{
			Family ch;//create empty Family for delete the old family
			file.seekp(sizeof(Family) * (numfamily1 - 1));
			file.write((char*)&ch, sizeof(Family));
		}
	}
	file.clear();
}
int count(fstream& file, int numactivity) {
	int count = 0;
	for (int i = 0;i < 100;i++) {
		Family temp;
		file.seekg(sizeof(Family) * i);
		file.read((char*)&temp,sizeof(Family));
		if ((temp.getactivity() & numactivity)!=0) {
			count++;
		}
	}
	file.clear();
	return count;
	
}
void update(fstream& file, int numfamily1, queue<Family>& vec) {
	Family check;
	short want = 0;
	short cant = 0;
	file.seekg(sizeof(Family) * (numfamily1 - 1));
	file.read((char*)&check, sizeof(Family));
	file.clear();
	if (numfamily1 > 100)
		throw  "ERROR: Invalid family number";
	else {
		if (check.getnumfamily() == 0) {
			throw  "ERROR: Family is not in the file";
		}
		else {
			char ch;
			cout << "Do you want to register for swimming?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {
				
				if ((count(file,SWIMMING)) < 10) {
					want += SWIMMING;
				}
				else
					cant += SWIMMING;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for gymnastics?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file,GYMNATSTICS) < 10) {
					want += GYMNATSTICS;
				}
				else
					cant += GYMNATSTICS;
		    }
			else {
			 if ((ch != 'n') && (ch != 'N'))
				throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for dance?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file, DANCE) < 10) {
					want += DANCE;
				}
				else
					cant += DANCE;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for art?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file, ART) < 10) {
					want +=ART;
				}
				else
					cant += ART;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for self defense?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file, SELF_DEFENSE) < 10) {
					want += SELF_DEFENSE;
				}
				else
					cant += SELF_DEFENSE;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for music?"<< endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file,MUSIC) < 10) {
					want += MUSIC;
				}
				else
					cant += MUSIC;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register for drama?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file, DRAMA) < 10) {
					want += DRAMA;
				}
				else
					cant += DRAMA;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			cout << "Do you want to register basketball?" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {

				if (count(file, BASKETBALL) < 10) {
					want += BASKETBALL;
				}
				else
					cant += BASKETBALL;
			}
			else {
				if ((ch != 'n') && (ch != 'N'))
					throw "ERROR: Invalid response";
			}
			Family temp = check;
			if (cant != 0) {
				temp.setactivity(cant);
				vec.push(temp);
			}
			check.setactivity(want);
			file.seekp(sizeof(Family)* (numfamily1 - 1));
			file.write((char*)&check, sizeof(Family));
			file.clear();
		}
	}
		
}
void waiting(queue<Family>& vec) {
	queue<Family>& temp = vec;
	while (!temp.empty()) {
		Family help = temp.front();
		temp.pop();
		cout << help;
		if (help.getactivity() & SWIMMING)
			cout << "SWIMMING" << endl;
		if (help.getactivity() & GYMNATSTICS)
			cout << "GYMNATSTICS" << endl;
		if (help.getactivity() & DANCE)
			cout << "DANCE" << endl;
		if (help.getactivity() & ART)
			cout << "ART" << endl;
		if (help.getactivity() & SELF_DEFENSE)
			cout << "SELF_DEFENSE" << endl;
		if (help.getactivity() & MUSIC)
			cout << "MUSIC" << endl;
		if (help.getactivity() & DRAMA)
			cout << "DRAMA" << endl;
		if (help.getactivity() & BASKETBALL)
			cout << "BASKETBALL" << endl;
	}
}
void print(fstream& file, int numfamily1) {
	if (numfamily1 > 100)
		throw  "ERROR: Invalid family number";
	else {
		Family check;
		file.seekg(sizeof(Family) * (numfamily1 - 1));
		file.read((char*)&check, sizeof(int));
		file.clear();
		if (check.getnumfamily() == 0) {
			throw  "ERROR: Family is not in the file";
		}
		else
		{
			Family helpme;
			file.seekg(sizeof(Family) * (numfamily1 - 1));
			file.read((char*)&helpme, sizeof(Family));
			cout << helpme;
			if (helpme.getactivity() & SWIMMING)
				cout << "SWIMMING" << endl;
			if (helpme.getactivity() & GYMNATSTICS)
				cout << "GYMNATSTICS" << endl;
			if (helpme.getactivity() & DANCE)
				cout << "DANCE" << endl;
			if (helpme.getactivity() & ART)
				cout << "ART" << endl;
			if (helpme.getactivity() & SELF_DEFENSE)
				cout << "SELF_DEFENSE" << endl;
			if (helpme.getactivity() & MUSIC)
				cout << "MUSIC" << endl;
			if (helpme.getactivity() & DRAMA)
				cout << "DRAMA" << endl;
			if (helpme.getactivity() & BASKETBALL)
				cout << "BASKETBALL" << endl;
				
			file.clear();
		}
	}
}
void handleCount(fstream& file) {
	int snum;
	cout << "enter activity number to count:\n";
	cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
	cin >> snum;
	cout << "there are ";
	switch (snum) {
	case 1:
		cout << count(file, SWIMMING);
		break;
	case 2:
		cout << count(file, GYMNATSTICS);
		break;
	case 3:
		cout << count(file, DANCE);
		break;
	case 4:
		cout << count(file, ART);
		break;
	case 5:
		cout << count(file, SELF_DEFENSE);
		break;
	case 6:
		cout << count(file, MUSIC);
		break;
	case 7:
		cout << count(file, DRAMA);
		break;
	case 8:
		cout << count(file, BASKETBALL);
		break;
	}
	cout << " families registered\n";
}

int main()
{


	queue<Family> q;
	fstream file;
	file.open("families.txt", ios::binary | ios::out);

	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	file.close();

	file.open("families.txt", ios::binary | ios::in | ios::out);
	int choice;
	int snum;
	
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
	cout << "enter 0-6:\n";
	cin >> choice;
	while (choice)
	{
		try {
			switch (choice)
			{
			case ADD://add to the file
				add(file);
				break;
			case DEL://delete from file
				cout << "enter number of family to delete:\n";
				cin >> snum;
				del(file, snum);
				break;
			case COUNT:
				handleCount(file);
				break;
			case UPDATE://update the list of classes of a family
				cout << "enter number of family to update:\n";
				cin >> snum;
				update(file, snum, q);
				break;
			case WAITING://update the list of classes for waiting fam 			
				waiting(q);
				break;

			case PRINT://print the details of a specific family
				cout << "enter number of family to print:\n";
				cin >> snum;
				print(file, snum);
				break;
			default:
				cout << "ERROR: invalid choice\n";

			}
		}// try
		catch (const char* msg) {
			cout << msg << endl;
		}
		cout << "\nenter 0-6:\n";
		cin >> choice;

	}
	file.close();
	return 0;
}
/*
* Choices are:
0 to exit
1 to add a family
2 to delete a family
3 to  count number of families signed up
4 to update the activities of a family
5 print the waiting list
6 to print a family

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
5 aaron 5 0505551235

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
123 brian 7 0505551123

ERROR: Invalid family number

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
5  aaron  5 0505551235

ERROR: Family is already in the file

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
6 carly 8 0505551236

enter 0-6:
1

enter the family's:  id, name, amount of people and a phone number:
7 daniella 9  0505551237

enter 0-6:
2

enter number of family to delete:
6
enter 0-6:
4
enter number of family to update:
6
ERROR: Family is not in the file

enter 0-6:
4

enter number of family to update:
5

Do you want to register for swimming?
Y
Do you want to register for gymnastics?
Y
Do you want to register for dance?
Y
Do you want to register for art?
Y
Do you want to register for self defense?
N
Do you want to register for music?
N
Do you want to register for drama?
N
Do you want to register basketball?
N

enter 0-6:
4
enter number of family to update:
7
Do you want to register for swimming?
Y
Do you want to register for gymnastics?
N
Do you want to register for dance?
Y
Do you want to register for art?
N
Do you want to register for self defense?
Y
Do you want to register for music?
N
Do you want to register for drama?
Y
Do you want to register basketball?
N
enter 0-6:
3

enter activity number to count:
Choices are:
1 SWIMMING
2 GYMNASTICS
3 DANCE
4 ART
5 SELF DEFENSE
6 MUSIC
7 DRAMA
8 BASKETBALL
1

there are 2 families registered

enter 0-6:
6

enter number of family to print:
5

family name: aaron
number of persons: 5
phone number: 505551235
!2!15
SWIMMING
GYMNASTICS
DANCE
ART

enter 0-6:
6

enter number of family to print:
6
ERROR: Family is not in the file

enter 0-6:
6

enter number of family to print:
7

family name: Daniella
number of persons: 9
phone number: 505551237
SWIMMING
DANCE
SELF DEFENSE
DRAMA
enter 0-6:
6

enter number of family to print:
8
ERROR: Family is not in the file

enter 0-6:
5

enter 0-6:
0

*/