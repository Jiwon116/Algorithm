#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

#define RED 0       // 빨강
#define GREEN 1     // 초록
#define BLUE 2      // 파랑

using namespace std;

int n; 
int board[1001][1001];
ll memo[1001][3];

ll dp(int x, int ex_color, int st_color) {
    if (x == n) return 0;

    ll &ret = memo[x][ex_color];
    if(ret != -1) return ret;

    ret = 1e9;

    for(int i = 0; i < 3; ++i) {
        if(x == n - 1) {
            if(i != ex_color && i != st_color)
                ret = min(ret, dp(x + 1, i, st_color) + board[x][i]);
            else continue;
        } else {
            if(i != ex_color)
                ret = min(ret, dp(x + 1, i, st_color) + board[x][i]);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    ll answer = 1e9;

    for(int i = 0; i < 3; ++i) {
        memset(memo, -1, sizeof(memo));
        answer = min(answer, dp(1, i, i) + board[0][i]);
    }

    cout << answer << '\n';

    return 0;
}