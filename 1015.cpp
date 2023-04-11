#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

vector<pii> v;
vector<int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back({num, i});
    }

    sort(v.begin(), v.end());

    p.resize(n);

    for(int i = 0; i < n; ++i) p[v[i].second] = i;

    for(auto e : p) cout << e << ' '; cout << '\n';
    
    return 0;
}