#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    double n; cin >> n;

    cout << fixed;
    cout.precision(10);

    cout << (n * n * sqrt(3)) / 4 << '\n';
    
    return 0;
}