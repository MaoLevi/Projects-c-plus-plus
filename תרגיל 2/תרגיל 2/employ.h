/*
maor levi
328301981
sadna
targil#1-2
the program recieve from the user value of employee and check how get salary more high
or how donate less to the company
*/
#pragma once
class employ
{
	int id;
	char name[21];
	float wage_h;//hour
	int work_h;//hour
	float sum;
	float salary;
public:
	double total(float sum, int work, float wage);
	void setsalary(float num);
	float getsalary();
	void setid(int num);
	int getid();
	void setname(char arr[]);
	char* getname();
	void setwage_h(float num);
	float getwage_h();
	void setwork_h(int num);
	int getwork_h();
	void setsum(float num);
	float getsum();
	
};

