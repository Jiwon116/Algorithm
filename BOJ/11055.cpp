#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n;
int arr[1001];
int memo[1001][1001];

int dp(int index, int num) {
    if(index == n + 1) return 0;

    int &ret = memo[index][num];
    if(ret != -1) return ret;

    if(arr[index] > num) ret = max(ret, dp(index + 1, arr[index]) + arr[index]);
    ret = max(ret, dp(index + 1, num));

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> arr[i];

    memset(memo, -1, sizeof(memo));

    // 앞으로 볼 거 (넣을지 말지 확인하는 인덱스), 직전에 넣은 값
    cout << dp(1, 0) << '\n';
    
    return 0;
}