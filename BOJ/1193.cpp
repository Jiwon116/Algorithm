#include <iostream>

using namespace std;

int x;

int main() {

	cin >> x;

	int i = 1;
	while (x > i) {
		x -= i;
		i++;
	}

	if (i % 2 == 1)
		cout << i + 1 - x << '/' << x << endl;
	else
		cout << x << '/' << i + 1 - x << endl;
	
	return 0;
}
