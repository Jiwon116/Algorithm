#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int t, n;
int board[501];
int memo[501][501];

int dp(int start, int end) {
    if(start == end) return 0;

    int &ret = memo[start][end];
    if(ret != -1) return ret;

    int sum = 0;
    for(int i = start; i <= end; ++i) sum += board[i];

    ret = 1e9;
    for(int i = start; i <= end; ++i) ret = min(ret, dp(start, i) + dp(i + 1, end) + sum);


    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    while(t--) {
        memset(memo, -1, sizeof(memo));

        cin >> n;

        for(int i = 0; i < n; ++i) cin >> board[i];

        cout << dp(0, n - 1) << '\n';
    }
    
    return 0;
}