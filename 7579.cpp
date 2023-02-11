#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
int bytes[101];
int cost[101];
int memo[101][10001];

int dp(int cur, int res) {
    if(cur == n) return 0;

    int &ret = memo[cur][res];
    if(ret != -1) return ret;

    ret = dp(cur + 1, res);
    if(res >= cost[cur]) ret = max(ret, bytes[cur] + dp(cur + 1, res - cost[cur]));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) cin >> bytes[i];
    for(int i = 0; i < n; ++i) cin >> cost[i];

    int cnt = 0;

    while(dp(0, cnt) < m) cnt++;

    cout << cnt << '\n';
    
    return 0;
}