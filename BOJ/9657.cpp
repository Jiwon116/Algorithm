#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int memo[1001][2];

int dp(int x, int who) {
    if(x == 1 || x == 3 || x == 4) return who; // 상근이 이김
    if(x == 2) return who ^ 1;

    int &ret = memo[x][who];
    if(ret != -1) return ret;

    if(dp(x - 1, who ^ 1) == who || dp(x - 3, who ^ 1) == who || dp(x - 4, who ^ 1) == who) return ret = who;
    else return ret = who ^ 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    memset(memo, -1, sizeof(memo));
    
    // 상근이(0)가 마지막에 1개 또는 3개, 4개를 가져가면 이김
    if(dp(n, 0) == 1) cout << "CY" << '\n';
    else cout << "SK" << '\n';
    
    return 0;
}