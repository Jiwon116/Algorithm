#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<pii> v;

    for(int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }

    int cnt;

    for(int i = 0; i < n; ++i) {
        cnt = 1;

        for(int j = 0; j < n; ++j) {
            if(v[i].first < v[j].first && v[i].second < v[j].second) cnt++;
        }

        cout << cnt << " ";
    }

    return 0;
}