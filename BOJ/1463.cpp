#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int memo[1000001];

int dp(int num) {
    if(num == 1) return 0;

    int &ret = memo[num];
    if(ret != -1) return ret;

    ret = 1e9;

    if(num % 2 == 0) ret = min(ret, dp(num / 2) + 1);
    if(num % 3 == 0) ret = min(ret, dp(num / 3) + 1);
    ret = min(ret, dp(num - 1) + 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> n;

    memset(memo, -1, sizeof(memo));

	cout << dp(n) << '\n';

	return 0;
}
