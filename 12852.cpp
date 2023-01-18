#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int memo[1000001];
int answer[1000001];

int dp(int num) {
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
    memo[1] = 0;

	cout << dp(n) << '\n';

    while(n != 1) {
        cout << n << " ";

        int cnt = memo[n];

        if(n % 3 == 0 && cnt - 1 == memo[n / 3]) n /= 3;
        else if(n % 2 == 0 && cnt - 1 == memo[n / 2]) n /= 2;
        else n -= 1;
    }

    cout << "1\n";

	return 0;
}
