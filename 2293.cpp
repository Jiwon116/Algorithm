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

// 이전 코드
// memo를 1차원 배열로 만든 후 할 수 있는 방법..?
/*
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, k;
int coin[101];
int memo[101][10001];

int dp(int index, int sum) {
    if(sum == 0) return 1;
    if(index >= n) return 0;

    int &ret = memo[index][sum];
    if(ret != -1) return ret;

    ret = 0;
    if(sum >= coin[index]) ret = dp(index, (sum - coin[index])) + dp(index + 1, sum);
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));

    cin >> n >> k;

    for(int i = 0; i < n; ++i) cin >> coin[i];

    // coin[0] 에 들어있는 값부터 시작, 총합은 n
    cout << dp(0, k) << '\n';

    return 0;
}



*/