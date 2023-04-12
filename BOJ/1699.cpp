#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
ll memo[100001];

ll dp(int num) {
    if(num == 1) return 1;
    if(num == 0) return 0;

    ll &ret = memo[num];
    if(ret != -1) return ret;

    ret = 1e9;

    for(int i = sqrt(num); i >= 1; --i) {
        ret = min(ret, dp(num - (i * i)) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    cout << dp(n) << '\n';
    
    return 0;
}