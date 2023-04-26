#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

long long dp[10001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

	dp[0][0] = 1;

	for (int i = 1; i <= 10000; ++i) {
		dp[i][0] = dp[i - 1][0];

		if (i > 1) dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		if (i > 2) dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	
	while (n--) {
		int num; cin >> num;
		cout << dp[num][0] + dp[num][1] + dp[num][2] << '\n';
	}
    
    return 0;
}