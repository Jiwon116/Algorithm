#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;

    while(getline(cin, s)) {
        if(s != "END")
            for(int i = s.size() - 1; i >= 0; --i) cout << s[i];
            
        cout << '\n';
    }

    return 0;
}