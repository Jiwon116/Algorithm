#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t, s; cin >> t >> s;

    if(t >= 12 && t <= 16 && s == 0) cout << 320 << '\n';
    else cout << 280 << '\n';
    
    return 0;
}