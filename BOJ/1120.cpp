#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a, b; cin >> a >> b;

    int ans = 1e9;

    for(int i = 0; i < b.size() - a.size() + 1; ++i) {
        int cnt = 0;
        for(int j = 0; j < a.size(); ++j)
            if(a[j] != b[j + i]) cnt++;
        
        ans = min(ans, cnt);
    }

    cout << ans << '\n';
    
    return 0;
}