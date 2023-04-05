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
        if(s == "#") break;

        
        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' ||s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') cnt++;
        }

        cout << cnt << '\n';
    }
    
    return 0;
}