#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s[5];

    for(int i = 0; i < 5; ++i) cin >> s[i];

    for(int i = 0; i < 15; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(i < s[j].size()) cout << s[j][i];
        }
    }

    cout << '\n';
    
    return 0;
}