#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
int board[1001][1001];
int memo[1001][1001];

int dp(int x, int y) {
    if(x == n || y  == m) return 0;

    int &ret = memo[x][y];
    if(ret != -1) return ret;

    ret = 0;

    if(x > 0 || x <= n - 1) {
        ret = max(ret, dp(x + 1, y) + board[x][y]);
    }

    if(y > 0 || y <= m - 1) {
        ret = max(ret, dp(x, y + 1) + board[x][y]);
    }

    if(x > 0 || x <= n - 1 || y > 0 || y <= m - 1) {
        ret = max(ret, dp(x + 1, y + 1) + board[x][y]);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    
    cout << dp(0, 0) << '\n';

    return 0;
}