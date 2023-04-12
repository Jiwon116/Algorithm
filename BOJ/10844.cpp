#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n; // n만큼의 자리수 -> 33이면 33자리수
ll memo[10][101]; // 정답을 집어 넣는 배열 -> memo[1] = 9, memo[2] = 17...

// 계단 수는 각각의 자리수가 1 차이가 나면 됨
// 즉, 1이 오면 그 다음에 올 수 있는 수는 0 또는 2임
// 0은 1만 올 수 있음
ll dp(int cur, int index) {
    if (index == n) return 1;

    ll &ret = memo[cur][index];
    if(ret != -1) return ret;

    ret = 0;

    if (cur < 9) ret += dp(cur + 1, index + 1) % 1000000000;
    if (cur > 0) ret += dp(cur - 1, index + 1) % 1000000000;

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1 , sizeof(memo));
    
    cin >> n;

    ll answer = 0;

    // n자리수인데 1부터 시작한다
    for(int i = 1; i <= 9; ++i) answer += dp(i, 1);

    cout << answer % 1000000000 << '\n';
    
    return 0;
}