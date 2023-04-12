#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int l, n;
vector<char> v;

void func(int cur, string s, int vowel, int consonant) {
    s += v[cur];

    if(v[cur] == 'a' || v[cur] == 'e' || v[cur] == 'i' || v[cur] == 'o' || v[cur] == 'u') vowel++;
    else consonant++;
    

    if(s.size() == l && vowel >= 1 && consonant >= 2) {
        cout << s << '\n';

        return;
    }

    for(int i = cur + 1; i < n; ++i) func(i, s, vowel, consonant);

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> l >> n;

    for(int i = 0; i < n; ++i) {
        char c; cin >> c;
        v.push_back(c);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; ++i) func(i, "", 0, 0);
    
    return 0;
}