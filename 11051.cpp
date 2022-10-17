#include <iostream>

using namespace std;

int arr[1001][1001] = { 0, };

int main() {
	int n, k; cin >> n >> k;

    arr[0][0] = 1;
	arr[1][0] = 1;
    arr[1][1] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (j == 0 || i == j) arr[i][j] = 1;
			else {
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
			}
		}
	}
	
    cout << arr[n][k] << '\n';
	
    return 0;
}