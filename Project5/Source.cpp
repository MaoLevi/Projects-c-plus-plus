#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	
	string ch;
	cin >> ch;
	pop_back
    while(ch)
	if (sizeof(arr) % 3 != 0) {
		cout << "false";
		return 0;
	}
	int = (sizeof(arr)/3);
	bool check = true;
	for (int i = 0;i < sizeof(arr);i++) {
		if (arr[i] != arr[i + 1])
			check == false;
	}
	if (check == true) {
		cout << "true";
		return 0;
	}
	int j = 1;
	int counter = 0;
	while (arr[0] != arr[j])
		counter++;
	for (int r = 1;r < 4;r++) {
		for (int k = 0;k <= counter;k++)
			if (arr[k] != arr[k + counter]) {
				cout << "false";
				return 0;
			}

	}
	cout << "true";
	return 0;
}