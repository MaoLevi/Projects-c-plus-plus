/*
ary oz

*/
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Commander.h"
#include "Officer.h"
#include <iostream>
using namespace std;


enum option {
	EXIT,	//	���� �������
	ADD_NEW_SOLDIER,	//	����� ���� ���
	DESERVES_MEDAL,	//	����� ���� �� ������� ������ ���"�
	HIGHEST_SOCIOMETRIC,	//����� �� (����� �����) ��  ����� ��� ���� ��������� ������� 
	PRIVATE_MEDAL_COUNT,	//	����� ���� ������� ��������� ������ ���"�
	NONCOMBAT_COMMANDER,	//	����� ���� (����� �����) �� ������� ����� �����
	SUPER_SOLDIER,   //����� ����� ������, ��� ���� ���� ������ ����� �- 15  ������ ������
	REMOVE_OFFICER,	//	����� �� ������� ������� ��� ������ ��� ����� ����
};
void add(vector <Soldier*>& soldiers)//����\� �����- ������ �� ����� 
{
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	Soldier* soldier; //array for all soldier typs
	int choice;
	cin >> choice;

	//help veriables
	int id, missions;
	int* grade = NULL;
	string firstName, LastName;
	bool combt;
	float sociometric;

	if (choice == 1)//private
	{
		cout << "enter id, first name, last name and number of operations\n";
		cin >> id >> firstName >> LastName >> missions;
		grade = new int[missions];

		if (missions > 0)
		{
			cout << "enter " << missions << " grades\n";
			for (int i = 0; i < missions; i++)
				cin >> grade[i];
		}
		//array for private soldier
		soldier = new PrivateSoldier(id, firstName, LastName, missions, grade);
		soldiers.push_back(soldier);
		return;
	}
	if (choice == 2) //if user chose commander
	{
		cout << "enter id, first name, last name and number of operations\n";
		cin >> id >> firstName >> LastName >> missions;
		grade = new int[missions];

		if (missions)
		{
			cout << "enter " << missions << " grades\n";
			for (int i = 0; i < missions; i++)
				cin >> grade[i];
		}
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> combt;
		soldier = new Commander(id, firstName, LastName, missions, grade, combt);//array for commander
		soldiers.push_back(soldier);
		return;
	}

	if (choice == 3) //if user chose officer
	{
		cout << "enter id, first name, last name and number of operations\n";
		cin >> id >> firstName >> LastName >> missions;
		cout << "enter the sociometric score\n";
		cin >> sociometric;
		soldier = new Officer(id, firstName, LastName, missions, sociometric);//array for officer
		soldiers.push_back(soldier);
		return;
	}
}
void printMedalList(vector <Soldier*> medal)
//print the solders that can have "tzalash"
{
	vector <Soldier*>::iterator it;
	for (it = medal.begin(); it < medal.end(); it++)
		if ((*it)->Medal())
			(*it)->print();

}

Soldier* highesttSociometricScore(vector <Soldier*> score)
//print name of soldiers with highest sociometric score
{

	Soldier* soldi1 = NULL;
	int max = 0;
	vector <Soldier*> ::iterator it = score.begin();
	while (it != score.end())
	{
		if ((*it)->soldierType() == "officer")
		{
			if (((Officer*)*it)->getSociometricScore() > max)
			{
				max = ((Officer*)*it)->getSociometricScore();
				soldi1 = (*it);
			}
		}
		it++;
	}
	if (!max)
		return NULL;
	return soldi1;
}

int main()
{
	Soldier* s = NULL;
	vector <Soldier*> vector;   // ����� �� ������ �� ������
	int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER: {add(vector); } //����� ���� ���						
							break;
		case DESERVES_MEDAL: {printMedalList(vector); } //����� ���� ������ ���"�
						   break;
		case HIGHEST_SOCIOMETRIC:   //����� �� ����� ��� ���� ��������� ���� ����� 
			s = highesttSociometricScore(vector); // ����\� �����-����� �� �����
			cout << "Officer with the highest sociometric score: ";
			if (s != NULL)//if not null
				cout << s->getFirstName() << ' ' << s->getLastName() << endl;

			break;
		case PRIVATE_MEDAL_COUNT: { cout << "number of privates that received medals: ";
			cout << count_if(vector.begin(), vector.end(), [](Soldier* s)->bool {return((s->soldierType() == "private" && s->Medal())); });
			//����� ���� ������ ���"� ��������
			cout << endl; }
								break;

		case NONCOMBAT_COMMANDER: {cout << "list of noncombat commanders: ";    //����� �����(�� ����� �����) ������� ������� ����� �����
			for_each(vector.begin(), vector.end(), [](Soldier* s)->void {if (!((Commander*)s)->IsCOmbat() && s->soldierType() == "commander") { cout << " " << s->getFirstName() << " " << s->getLastName(); }});
			cout << endl; }
								break;
		case SUPER_SOLDIER:
			if (any_of(vector.begin(), vector.end(), [](Soldier* s)->bool {return(s->getnumMission() > 15); }))// ���� ���� ������ ����� �- 15 ������ ������
			{
				cout << "there is at least one soldier that did more than 15 operations\n";
			}
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER: {//����� ��������/����� �� �� ������ ������ ����� ������ ��� ������� ������
			auto it = remove_if(vector.begin(), vector.end(), [](Soldier* s)->bool {return(s->soldierType() == "officer" && s->getnumMission() == 0); });
			for_each(vector.begin(), it, [](Soldier* s)->void {s->print(); }); }
						   //����� �� ������ ���� ����� �������
						   break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
/*
enter 0 - 7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
1
enter id, first name, last nameand number of operations
111 aaa aaa 3
enter 3 grades
100 95 98
enter 0 - 7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
2
enter id, first name, last nameand number of operations
222 bbb bbb 0
enter 1 if the soldier is combat and 0 if not
1
enter 0 - 7
1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
3
enter id, first name, last nameand number of operations
333 ccc ccc 0
Enter the sociometric score
100
enter 0 - 7
3
Officer with the highest sociometric score : ccc ccc
enter 0 - 7
4
number of privates that received medals : 0
enter 0 - 7
5
list of noncombat commanders
enter 0-7
6
no soldier did more than 15 operations
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
commander
ID: 222
first name: bbb
last name: bbb
num operations: 0
combat: yes
enter 0-7
0
*/