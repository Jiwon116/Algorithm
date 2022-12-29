#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    deque<int> dq;
    dq.resize(n);

    for(int i = 0; i < n; ++i) cin >> dq[i];

    int ans = 0;

    while(dq.size() > 1 && ans <= 1440) {
        sort(dq.rbegin(), dq.rend());

        int x = dq[0] - dq[1];

        ans += dq[1];

        dq.pop_front();
        dq.pop_front();

        if(x) dq.push_back(x);
    }
    
    ans += dq[0];

    if(ans > 1440) cout << -1 << '\n';
    else cout << ans << '\n';
    
    return 0;
}