#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int p[1001];
int memo[1001];

int dp(int count) {
    if(count == 0) return 0;

    int &ret = memo[count];
    if(ret != -1) return ret;

    ret = p[count];

    for(int i = 1; i <= count; ++i) ret = min(ret, dp(count - i) + p[i]);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> p[i];

    cout << dp(n) << '\n';
    
    return 0;
}