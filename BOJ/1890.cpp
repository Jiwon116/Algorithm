#include <bits/stdc++.h>
#define ll long long
#define MAX 101

using namespace std;

int n;
int board[MAX][MAX];
ll memo[MAX][MAX]; 
// memo[i][j] : i, j 에 온적 있나?
// i, j -> (n - 1, n - 1) 도달할 수 있는 경우의 수

ll dp(int x, int y) {
    // base condition
    if (x >= n || y >= n) return 0;
    if (x == n - 1 && y == n - 1) return 1;
    if (board[x][y] == 0) return 0;

    ll &ret = memo[x][y];
    if (ret != -1) return ret;

    int jump = board[x][y];
    ret = dp(x, y + jump) + dp(x + jump, y);

    return ret;
}

int main() {

    memset(memo, -1LL, sizeof(memo));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cout << dp(0, 0) << "\n";
    return 0;
}