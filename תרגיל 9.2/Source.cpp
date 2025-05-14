#include<iostream>
#include <string>
#include "SearchTree.h"
#include "Book.h"
using namespace std;
enum choice { ADD = 'a', DELETE = 'b', SEARCH = 'c', PRINT = 'd', EXIT = 'e' };




int main()
{
	SearchTree<Book> NewBook;
	Book M1;

	char inputChoice;
	cout << "enter a-e:" << endl;
	cin >> inputChoice;
	while ('e' != inputChoice) {
		switch (inputChoice) {
		case ADD:
		{
			cout << "enter a book" << endl;
			cin >> M1;
			NewBook.add(M1);
			break;
		}
		case DELETE:
		{
			cout << "enter a book" << endl;
			cin >> M1;
			if (!NewBook.search(M1))
				cout << "not exist" << endl;
			else
				NewBook.remove(M1);
			break;
		}
		case SEARCH:
		{
			cout << "Enter A Book" << endl;
			cin >> M1;
			if (!NewBook.search(M1))
				cout << "Not Exist" << endl;
			else
				cout << "Exist" << endl;
			break;
		}
		case PRINT:
		{
			NewBook.inOrder();
			break;
		}
		default:

			cout << "ERROR" << endl;
			break;

		}
		cout << "enter a-e:" << endl;
		cin >> inputChoice;
	}
	return 0;
}

/*

enter a - e:
a
enter a book :
2 b b
enter a - e :
	a
	enter a book :
5 e e
enter a - e :
	a
	enter a book :
1 a a
enter a - e :
	a
	enter a book :
4 d d
enter a - e :
	a
	enter a book :
7 g g
enter a - e :
	a
	enter a book :
3 c c
enter a - e :
	b
	enter a book :
5 e e
enter a - e :
	d
	1 a a
	2 b b
	3 c c
	4 d d
	7 g g
	enter a - e:
e

*/