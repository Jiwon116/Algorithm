#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int p[1001]; // 카드가 i개 포함된 카드팩의 가격 Pi
ll memo[1001][1001];

ll dp(int index, int count) {
    if(index == n + 1) return 0;
    if(count == 0) return 0;

    ll &ret = memo[index][count];
    if(ret != -1) return ret;

    ret = 0;
    if(count >= index) ret = max(ret, dp(index, count - index) + p[index]);
    ret = max(ret, dp(index + 1, count));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> p[i];

    // 1번째 인덱스부터 시작할거고, 총 구매해야 하는 카드의 양은 n이다
    cout << dp(1, n) << '\n';
    
    return 0;
}