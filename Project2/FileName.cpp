/*
maor levi 328301981
ari oz 321918484
sadna
targil #5-2

*/
#include "List2.h"
#include <iostream>
using namespace std;

List2 merge(List2& l1, List2& l2)
{
	int x;
	List2 merg;
	while (!l1.isEmpty() && !l2.isEmpty())
	{
		if (l1.firstElement() > l2.firstElement())  // insert the biger number to merg
		{
			x = l1.firstElement();
			merg.insert(x);
			l1.removeFirst();
		}
		else {
			x = l2.firstElement();
			merg.insert(x);
			l2.removeFirst();
		}
	}
	while (!l2.isEmpty()) {

		x = l2.firstElement();
		merg.insert(x);
		l2.removeFirst();

	}
	while ((!l1.isEmpty()))
	{
		x = l1.firstElement();
		merg.insert(x);
		l1.removeFirst();
	}

	
	return merg;
}

void makeSet(List2& l)
{
	List2 h;
	if (l.isEmpty())
	{
		return;
	}
	else {
		h=l;
		int value=h.firstElement();
		h.removeFirst();
		while (!h.isEmpty()) {

			if (value == h.firstElement()) {

				l.remove(value);
			}
			value = h.firstElement();
			h.removeFirst();
				

		}
	}

}

void reverse(List2 &l)
{
	List2 R;
	int x;

	while(!l.isEmpty()){
			
		R.add(l.firstElement());
		
		l.removeFirst();
	}
	l = R;
	
}



int main()
{
	List2 lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	reverse(mergedList);
	cout << "the new merged reverse: " << mergedList << endl;


	return 0;
}
/*
enter sorted values for the first list :
6 5 4 3 2 1 9
enter sorted values for the second list :
7 5 4 3 9
the new merged list : 7 6 5 5 4 4 3 3 2 1
the new merged set : 7 6 5 4 3 2 1
the new merged reverse : 1 2 3 4 5 6 7
*/