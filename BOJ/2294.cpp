#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int n, k;
vector<int> coin;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    coin.resize(n + 1);
    dp.resize(k + 1, INF);

    for(int i = 0; i < n; ++i) cin >> coin[i];

    dp[0] = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = coin[i]; j <= k; ++j) {
            dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
        }
    }

    if(dp[k] == INF) cout << -1 << '\n';
    else cout << dp[k] << '\n';

    return 0;
}