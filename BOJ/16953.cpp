#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int a, b; 
map<ll, ll> memo;

ll dp(ll x) {
    if (x == b) return 0;
    if (x > b) return 1e9;

    if(memo.find(x) != memo.end()) return memo[x];

    // 연산의 최솟값
    memo[x] = min(dp(x * 2), dp(x * 10 + 1)) + 1;

    return memo[x];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a >> b;

    // a부터 시작 b까지
    if(dp(a) >= 1e9) cout << -1 << '\n';
    else cout << dp(a) + 1 << '\n';
    
    return 0;
}