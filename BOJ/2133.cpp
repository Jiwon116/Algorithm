#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    int dp[31];

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for(int i = 3; i <= n; ++i) {
        if(i % 2 != 0) dp[i] = 0;
        else {
            for(int j = 2; j <= n; j += 2) {
                if(j == 2) dp[i] = dp[i - j] * dp[2];
                else if((i - j) >= 0) dp[i] += dp[i - j] * 2;
            }
        }
    }

    cout << dp[n] << '\n';
    
    return 0;
}