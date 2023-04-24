#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

ll gcd(ll x, ll y) {
    return x % y ? gcd(y, x % y) : y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll a, b; cin >> a >> b;

    ll ans = gcd(a, b);

    while(ans--) cout << 1; cout << '\n';
    
    return 0;
}