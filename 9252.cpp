#include <bits/stdc++.h>

// DP(LCS) + 백트래킹

using namespace std;

int LCS[1001][1001];
string answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s1, s2; cin >> s1 >> s2;

    for(int i = 1; i <= s1.size(); ++i) {
        for(int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    
    cout << LCS[s1.size()][s2.size()] << '\n';

    int idx1 = s1.size();
    int idx2 = s2.size();

    while(idx1 != 0 && idx2 != 0) {
        if(LCS[idx1][idx2] == LCS[idx1 - 1][idx2]) idx1--;
        else if(LCS[idx1][idx2] == LCS[idx1][idx2 - 1]) idx2--;
        else {
            answer += s1[idx1 - 1];
            idx1--;
            idx2--;
        }
    }

    for(int i = answer.size() - 1; i >= 0; --i) cout << answer[i]; cout << '\n';

    return 0;
}