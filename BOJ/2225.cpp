#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[201][201] = {0,};

int main() {
    int n, k; cin >> n >> k;

    for(int i = 1; i <= 200; ++i) {
        dp[1][i] = i;
        dp[i][1] = 1;
    }

    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= k; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000;
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}