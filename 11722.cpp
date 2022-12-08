#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

// LDS : Longest Decreasing Sequence

int n;
int arr[1001];
int memo[1001];

int dp(int index) {

    if(index == n) return 0;

    int &ret = memo[index];
    if(ret != -1) return ret;

    ret = 1; // 수열의 크기가 항상 1보다 크거나 같으므로 1로 초기화
    // index 다음 수부터 arr[index]에 들어있는 값보다 현재 값이 작은지 확인 후 길이 비교
    for(int i = index + 1; i < n; ++i) {
        if(arr[index] > arr[i]) ret = max(ret, dp(i) + 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 0; i < n; ++i) cin >> arr[i];

    memset(memo, -1, sizeof(memo));

    int answer = 0;
    // 0부터 n - 1까지의 lds
    for(int i = 0; i < n; ++i) answer = max(answer, dp(i));

    cout << answer << '\n';
    
    return 0;
}