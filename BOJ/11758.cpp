#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x1, y1, x2, y2, x3, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int result = ccw(x1, y1, x2, y2, x3, y3);

    if(result == 0) cout << 0 << '\n';
    else if(result > 0) cout << 1 << '\n';
    else cout << -1 << '\n';
    
    return 0;
}