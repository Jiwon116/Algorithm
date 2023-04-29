#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int dp[41];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];

    int temp;
    int result = 1;
    int prev = 0;

    while(m--) {
        cin >> temp;
        result *= dp[temp - prev - 1];
        prev = temp;
    }

    result *= dp[n - prev];
    
    cout << result << "\n";
    
    return 0;
}