#include <iostream>
#include <string>

#define MAX 1001

using namespace std;

int C = 0;

int main() {

	cin >> C;

	for (int i = 0; i < C; i++) {
		int num = 0;
		int grade[MAX] = { 0, };
		int sum = 0;
		int a = 0;
		float ans = 0.0;

		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> grade[j];
			sum += grade[j];
		}

		float avg = (float)sum / num;

		for (int k = 0; k < num; k++) {
			if (grade[k] > avg) {
				a++;
			}
		}
		ans = ((float)a / (float)num) * 100;

		cout << fixed;
		cout.precision(3);
		cout << ans << "%" << endl;
		
	}

	return 0;
}
