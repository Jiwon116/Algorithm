#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i = 1; i < 1001; ++i) {
        for(int j = 1; j <= i; ++j) {
            v.push_back(i);
        }
    }

    int n, m; cin >> n >> m;

    cout << accumulate(v.begin() + n - 1, v.begin() + m, 0) << '\n';

    // int cnt = 0;
    // for(int i = n - 1; i < m; ++i) cnt += v[i];
    // cout << cnt << '\n';
    
    return 0;
}