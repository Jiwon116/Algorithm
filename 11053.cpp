#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // dp를 1로 초기화 (내 자신이 가장 긴 수열이니까)
    for(int i = 0; i < 1001; ++i) dp[i] = 1;

    // arr = 10 20 10 30 20 50
    // dp =  1  2  1  3  2  4
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            // 나보다 작은 애라면 dp[j] + 1 하고
            // dp[i]와 비교해서 가장 큰 값을 저장
            if(arr[i] > arr[j]) dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    // dp중에 제일 큰 값을 출력
    int answer = -1;
    for(int i = 0; i < n; ++i) answer = max(answer, dp[i]);

    cout << answer << '\n';


    return 0;
}