#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int gcd(int x, int y) {
    int k;

    while(y != 0) {
        k = x % y;
        x = y;
        y = k;
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a, b; cin >> a >> b;

    // 최대공약수
    cout << gcd(a, b) << '\n' << (a * b) / gcd(a, b) << '\n';
    
    return 0;
}