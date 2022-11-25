#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s; cin >> s;

    for(int i = 0; i < s.length(); ++i) {
        if(i % 10 == 0 && i > 0) cout << '\n';
        cout << s[i];
    }
    
    return 0;
}