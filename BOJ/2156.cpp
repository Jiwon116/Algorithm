#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int drink[10001];
ll memo[10001][3];

ll dp(int index, int count) {
    if(index == n) return 0;

    ll &ret = memo[index][count];
    if(ret != -1) return ret;

    if(count == 2) ret = dp(index + 1, 0);
    else ret = max(dp(index + 1, count + 1) + drink[index], dp(index + 1, 0));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> drink[i];

    cout << dp(0, 0) << '\n';
    
    return 0;
}