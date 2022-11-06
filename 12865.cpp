#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, k;
int w[101];
int v[101];
ll memo[101][100001];

// 가치(v)가 가장 크면 됨
ll dp(int index, int weight) {
    if(index == n) return 0;    // 물건을 다 선택함
    if(weight == 0) return 0;

    ll &ret = memo[index][weight];
    if(ret != -1) return ret;

    ret = 0;
    if(weight >= w[index]) ret = max(ret, dp(index + 1, weight - w[index]) + v[index]); // index번째의 물건을 선택함
    ret = max(ret, dp(index + 1, weight)); // index번째 물건을 선택하지 않음

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(memo, -1, sizeof(memo));
    
    // 물건의 총 개수 n
    // 베낭의 최대 무게는 k
    cin >> n >> k;

    for(int i = 0; i < n; ++i) cin >> w[i] >> v[i]; // 각 물건의 무게와 가치

    // 물건을 아무것도 선택하지 않은 상태부터 시작
    cout << dp(0, k) << '\n';
    
    return 0;
}