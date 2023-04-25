#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, s, m; cin >> n >> s >> m;

    int arr[101];
    int dp[101][1001];

    for(int i = 1; i <= n; ++i) cin >> arr[i];

    dp[0][s] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(dp[i - 1][j] == 1) {
                if(j + arr[i] <= m) dp[i][j + arr[i]] = 1;
                if(j - arr[i] >= 0) dp[i][j - arr[i]] = 1;
            }
        }
    }

    for(int i = m; i >= 0; --i) {
        if(dp[n][i] == 1) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    
    return 0;
}