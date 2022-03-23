#include <iostream>
#include <string>

#define MAX 81

using namespace std;

int testcase = 0;

int main() {

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		string input;
		int answer = 0;
		int total = 0;

		cin >> input;

		for (int j = 0; j < input.length(); j++) {
			if (input[j] == 'O') {
				answer++;
				total += answer;
			}
			else {
				answer = 0;
			}
		}

		cout << total << "\n";
	}

	return 0;
}
