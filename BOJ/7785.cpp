#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    map<string, string> m;

    int n; cin >> n;

    while(n--) {
        string name, state; cin >> name >> state;
        m[name] = state;
    }

    for(auto e = m.rbegin(); e != m.rend(); ++e) {
        if(e->second == "enter") cout << e->first << "\n";
    }
    
    return 0;
}