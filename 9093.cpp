#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    cin.ignore();

    while(n--) {
        string s, word;

        getline(cin, s);
        stringstream ss(s);

        while(getline(ss, word, ' ')) {
            reverse(word.begin(), word.end());
            cout << word << ' ';
        }

        cout << '\n';
    }

    return 0;
}