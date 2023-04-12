#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    while(n--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        double dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
        int r3 = r1 > r2 ? r1 - r2 : r2 - r1;

        if(dist == 0 && r1 == r2) cout << -1 << '\n';
        else if(r1 + r2 == dist || r3 == dist) cout << 1 << '\n';
        else if(r3 < dist && dist < (r1 + r2)) cout << 2 << '\n';
        else cout << 0 << '\n';
    }
    
    
    return 0;
}