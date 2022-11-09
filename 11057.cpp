#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
ll memo[11][1001];

ll dp(int num, int index) {
    if(num >= 10) return 0;
    if(index == n - 1) return 1;

    ll &ret = memo[num][index];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = num; i <= 9; ++i) {
        ret += dp(i, index + 1) % 10007;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;   // n 자리수

    int answer = 0;
    // 0부터 시작하고 n자리수 이다
    for(int i = 0; i <= 9; ++i) {
        answer += dp(i, 0);
    }

    cout << answer % 10007 << '\n';
    
    return 0;
}