#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s; cin >> s;

    vector<string> v;
    
    for(int i = 0; i < s.size(); ++i) v.push_back(s.substr(i, s.size()));

    sort(v.begin(), v.end());

    for(auto e : v) cout << e << '\n';
    
    return 0;
}