#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s; cin >> s;

    sort(s.rbegin(), s.rend());

    if (s[s.length() - 1] != '0') cout << -1;
    else {
        long long sum = 0;

        for (auto e : s) {
            sum += e - '0';
        }

        if (sum % 3 == 0) cout << s;
        else cout << -1;
    }
    
    return 0;
}