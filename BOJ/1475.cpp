#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> v;
    v.resize(11);

    string s; cin >> s;

    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '9') v[6]++;
        else v[s[i] - '0']++;
    }

    v[6] = (v[6] + 1) / 2;

    cout << *max_element(v.begin(), v.end()) << '\n';

    return 0;
}