#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a[101][101];
    int b[101][101];

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num; cin >> num;
            a[i][j] = num;
        }
    }

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num; cin >> num;
            b[i][j] = num;
        }
    }

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] + b[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}