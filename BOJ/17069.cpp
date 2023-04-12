#include <bits/stdc++.h>
#define ll long long
#define MAX 33

#define HORIZONTAL 0    // 가로
#define VERTICAL 1      // 세로
#define DIAGONAL 2      // 대각선

using namespace std;

int n;
int board[MAX][MAX];
ll memo[MAX][MAX][3];

ll dp(int x, int y, int dir) {

    if(x == n - 1 && y == n - 1) return 1;

    ll &ret = memo[x][y][dir];
    if(ret != -1) return ret;

    ret = 0;
    if (dir == HORIZONTAL) {
        if (y + 1 < n && board[x][y + 1] != 1) {
            ret += dp(x, y + 1, dir);
        }

        if (y + 1 < n && x + 1 < n && board[x + 1][y] + board[x][y + 1] + board[x + 1][y + 1] == 0) {
            ret += dp(x + 1, y + 1, DIAGONAL);
        }

    } else if (dir == VERTICAL) {
        if (x + 1 < n && board[x + 1][y] != 1) {
            ret += dp( x + 1, y, dir);
        }

        if (y + 1 < n && x + 1 < n && board[x + 1][y] + board[x][y + 1] + board[x + 1][y + 1] == 0) {
            ret += dp(x + 1, y + 1, DIAGONAL);
        }

    } else if (dir == DIAGONAL) {
        if (y + 1 < n && board[x][y + 1] != 1) {
            ret += dp(x, y + 1, HORIZONTAL);
        }

        if (y + 1 < n && x + 1 < n && board[x + 1][y] + board[x][y + 1] + board[x + 1][y + 1] == 0) {
            ret += dp(x + 1, y + 1, dir);
        }

        if (x + 1 < n && board[x + 1][y] != 1) {
            ret += dp( x + 1, y, VERTICAL);
        }
    }

    return ret;
}

int main() {

    memset(memo, -1LL, sizeof(memo));

    cin >> n;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    cout << dp(0, 1, HORIZONTAL) << '\n';

    return 0;
}