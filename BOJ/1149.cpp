#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

#define RED 0       // 빨강
#define GREEN 1     // 초록
#define BLUE 2      // 파랑

using namespace std;

int n; 
int board[1001][1001]; // 색칠하는 비용
ll memo[1001][3];

ll dp(int x, int color) {
    // ret이 나타내는 건 최소 비용
    // 따라서 ret이 가장 작은지 확인한 후 return 해줘야 함

    if (x == n) return 0;

    ll &ret = memo[x][color];
    if(ret != -1) return ret;

    ret = 1e9;

    for(int i = 0; i < 3; ++i) {
        if (i == color) continue;
        ret = min(ret, dp(x + 1, i) + board[x][i]);
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
    // dp(0, 0) 부터 시작
    for(int i = 0; i < 3; ++i) {
        memset(memo, -1, sizeof(memo));
        // dp(x, color)는 집 x를 칠할건데, 이전의 집(x-1)이 i 색깔이다
        // 따라서, x는 i 색깔이면 안된다
        answer = min(answer, dp(1, i) + board[0][i]);
    }

    cout << answer << '\n';

    return 0;
}