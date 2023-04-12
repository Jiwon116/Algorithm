#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int t, n;
int score[2][100005];
int memo[2][100005];

int dp(int x, int y) {
    if(y >= n) return 0;

    int &ret = memo[x][y];
    if(ret != -1) return ret;

    ret = max(dp((x + 1) % 2, y + 1), dp((x + 1) % 2, y + 2)) + score[x][y];

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    while(t--) {
        memset(memo, -1, sizeof(memo));
        memset(score, 0, sizeof(score));

        cin >> n;

        for(int i = 0; i < 2; ++i) 
            for(int j = 0; j < n; ++j)
                cin >> score[i][j];

        // [0, 0] 부터 시작
        cout << max(dp(0, 0), dp(1, 0)) << '\n';
    }
    
    return 0;
}