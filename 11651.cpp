#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;

    vector< pair<int, int> > v; 

    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), [] (const pair<int, int> &a, const pair<int, int> &b) -> bool {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    for(pair<int, int> e : v) cout << e.first << " " << e.second << "\n";

    return 0;
    
    return 0;
}