#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int arr[501][2];
int memo[501][501];

int dp(int x, int y) {
    if(x == y) return 0;
    
    int &ret = memo[x][y];
    if (ret != -1) return ret;

    ret = 1e9;

    for(int i = x; i < y; ++i) 
        ret = min(ret, dp(x, i) + dp(i + 1, y) + arr[x][0] * arr[i][1] * arr[y][1]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> arr[i][0] >> arr[i][1];

    dp(0, n - 1);

    cout << memo[0][n - 1] << '\n';
    
    return 0;
}