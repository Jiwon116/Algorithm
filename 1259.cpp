#include <iostream>
#include <algorithm>

using namespace std;

string input;

int main() {
	while(input != "0") {
		cin >> input;

		string buf = input;

		reverse(input.begin(), input.end());

		if(input != "0") {
			if(input == buf) cout << "yes\n";
			else cout << "no\n";
		}
	}
	
	return 0;
}