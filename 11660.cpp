#include <bits/stdc++.h>

using namespace std;

int arr[1025][1025];
int sum[1025][1025];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> arr[i][j];

            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + arr[i][j];
        }
    }

    while(m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}