#include <iostream>

using namespace std;

int arr[31][31] = {0, };

int main() {
    int n, k; cin >> n >> k;

    arr[0][0] = 1;

    for(int i = 1; i < n; ++i) {
        if(arr[i][0] == 0 || arr[0][i] == 0) {
            arr[i][0] = 1;
            arr[0][i] = 1;
        }
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            if(arr[i][j] == 0) arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    cout << arr[n - k][k - 1] << '\n';

    return 0;
}