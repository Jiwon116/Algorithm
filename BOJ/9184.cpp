#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;
int memo[101][101][101];

int dp(int a, int b, int c) {
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return 1048576;

    int &ret = memo[a][b][c];
    if(ret != -1) return ret;

    if(a < b && b < c) ret = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a, b - 1, c);
    else ret = dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a, b, c; 

    memset(memo, -1, sizeof(memo));
    
    while(cin >> a >> b >> c) {
        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << dp(a, b, c) << '\n';
    }
    
    return 0;
}