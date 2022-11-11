#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
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
    dp.resize(k + 1);

    for(int i = 0; i < n; ++i) cin >> coin[i];

    dp[0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = coin[i]; j <= k; ++j) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k] << '\n';

    return 0;
}