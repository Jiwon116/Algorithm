#include <bits/stdc++.h>

using namespace std;

int LCS[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s1, s2; cin >> s1 >> s2;

    for(int i = 1; i <= s1.length(); ++i) {
        for(int j = 1; j <= s2.length(); ++j) {
            if (s1[i - 1] == s2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    
    cout << LCS[s1.length()][s2.length()] << '\n';

    return 0;
}