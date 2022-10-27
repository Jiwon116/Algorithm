#include <bits/stdc++.h>

using namespace std;

int LCS[101][101][101];

int main() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    for(int i = 1; i <= s1.length(); ++i) {
        for(int j = 1; j <= s2.length(); ++j) {
            for(int k = 1; k <= s3.length(); ++k) {
                if(s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1] && s2[j - 1] == s3[k - 1])
                    LCS[i][j][k] = LCS[i - 1][j - 1][k - 1] + 1;
                else LCS[i][j][k] = max(max(LCS[i - 1][j][k], LCS[i][j - 1][k]), LCS[i][j][k - 1]);
            }
        }
    }

    cout << LCS[s1.length()][s2.length()][s3.length()] << '\n';

    return 0;
}