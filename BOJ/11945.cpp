#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    
    vector<string> v;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        v.push_back(s);
    }

    for(int i = 0; i < n; ++i) {
        reverse(v[i].begin(), v[i].end());
        cout << v[i] << '\n';
    }
    
    return 0;
}