#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll cal(ll a, ll b, ll c) {
    ll res = 1;

    while (b) {
        if (b % 2) { res = (res * a) % c; }

        a = (a * a) % c;
        b /= 2;
    }

    return res;
}
 
int main() {

    ll a, b, c; cin >> a >> b >> c;

    cout << cal(a, b, c) % c << '\n';

    return 0;
}