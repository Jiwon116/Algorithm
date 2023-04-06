#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    int ans = 0;

    for(int i = 2; i <= n; ++ans) i += 6 * ans; 

    if(n == 1) ans = 1;

    cout << ans << '\n';
    
    return 0;
}