#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < n; ++i) v.push_back(i + 1);

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        swap(v[a - 1], v[b - 1]);
    }

    for(auto e : v) cout << e << " "; cout << '\n';
    
    return 0;
}