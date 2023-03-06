#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<pair<pii, pair<int, string> > > v(n); // 년도, 월, 일 ,이름

    for(int i = 0; i < n; ++i)
        cin >> v[i].second.second >> v[i].second.first >> v[i].first.second >> v[i].first.first;

    sort(v.begin(), v.end());

    cout << v[n - 1].second.second << '\n' << v[0].second.second << '\n';
    
    return 0;
}