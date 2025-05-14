#include "List2.h"
#include <iostream>
using namespace std;

List2 merge(List2& l1, List2& l2)
{
	int x;
	List2 merg;
	while (!l1.isEmpty() || !l2.isEmpty())
	{
		if (l1.isEmpty()) {
			x = l2.firstElement();
			merg.insert(x);
			l2.removeFirst();

		}
		else
		{

			if (l2.isEmpty()) {
				x = l1.firstElement();
				merg.insert(x);
				l1.removeFirst();
			}
			else
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
		}
	}


	return merg;
}

void makeSet(List2 l)
{
	List2 h;
	if (l.isEmpty())
	{
		return;
	}
	else {
		h.add(l.firstElement());
		l.removeFirst();
		while (!l.isEmpty()) {
			if (h.search(l.firstElement()) == false) {
				h.add(l.firstElement());
			}

		}
	}

}

void reverse(List2 l)
{
	List2 R;
	int x;

	if (!l.isEmpty()) {

		//reverse the order
		x = l.firstElement();
		l.removeFirst();
		reverse(l);
	}
	R.add(x);
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