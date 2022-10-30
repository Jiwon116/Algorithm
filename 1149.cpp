#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

#define RED 0       // 빨강
#define GREEN 1     // 초록
#define BULE 2      // 파랑

using namespace std;

int n; 
int board[1001][1001];
ll memo[1001][1001][3];

int dp(int x, int y, int color) {
    // ret이 나타내는 건 최소 비용
    // 따라서 ret이 가장 작은지 확인한 후 return 해줘야 함

    if (x == n - 1 && y == 3 ) return 0;

    ll &ret = memo[x][y][color];
    if(ret != -1) return ret;


    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> board[i][j];
        }
    }

    dp(0, 0, 0);

    return 0;
}