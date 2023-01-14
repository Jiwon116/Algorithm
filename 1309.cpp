#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

#define nothing 0
#define left 1
#define right 2

using namespace std;

int n;
int memo[100001][3];

int dp(int num, int line) {
    if(num == 1) return 1;

    int &ret = memo[num][line];
    if(ret != -1) return ret;

    ret = 0;

    if(line == nothing) ret = dp(num - 1, nothing) + dp(num - 1, left) + dp (num - 1, right);
    else if (line == left) ret = dp(num - 1, right) + dp(num - 1, nothing);
    else ret = dp(num - 1, left) + dp(num - 1, nothing);

    return ret % 9901;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    cout << (dp(n, nothing) + dp(n, left) + dp(n, right)) % 9901 << '\n';
    
    return 0;
}