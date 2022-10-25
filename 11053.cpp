#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int memo[1001];
int n;

int main1() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // dp를 1로 초기화 (내 자신이 가장 긴 수열이니까)
    for(int i = 0; i < 1001; ++i) memo[i] = 1;

    // arr = 10 20 10 30 20 50
    // memo =  1  2  1  3  2  4
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            // 나보다 작은 애라면 memo[j] + 1 하고
            // memo[i]와 비교해서 가장 큰 값을 저장
            if(arr[i] > arr[j]) memo[i] = max(memo[j] + 1, memo[i]);
        }
    }

    // dp중에 제일 큰 값을 출력
    int answer = -1;
    for(int i = 0; i < n; ++i) answer = max(answer, memo[i]);

    cout << answer << '\n';


    return 0;
}

int dp(int index) {

    // base condition
    if (index == n) return 0;

    int &ret = memo[index];
    if (ret != -1) return ret;

    ret = 1;
    for (int i = index + 1; i < n; ++i) {
        if (arr[index] < arr[i]) {
            ret = max(ret, dp(i) + 1);
        }
    }

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    memset(memo, -1, sizeof(memo));

    // dp(i) : i 번째 ~ n - 1번째 의 수를 가지고 만들 수 있는 lis
    cout << dp(0) << "\n";
}