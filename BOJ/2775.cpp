#include <iostream>

#define MAX 15
using namespace std;

// k층의 n호에 살려면 k-1층의 1호부터 n호까지 사람들의 수의 합 만큼 데려와서 살아야한다

// 2층 1	4	10	20	35
// 1층 1	3	6	10	15	
// 0층 1	2	3	4	5	...	14
int main() {
	// t : 테스트케이스
	// k : k층
	// n : n호
	int t, k, n = 0;
	int p[MAX][MAX] = { 0, };

	p[0][0] = 0;

	for (int i = 1; i < 15; i++) {
		p[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			p[i][j] = p[i - 1][j] + p[i][j - 1];
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> k >> n;

		cout << p[k][n] << endl;
	}

	return 0;
}
