// 조합 + DP
#include <iostream>
#include <string.h>
#define MAX 31

using namespace std;

long long memo[MAX][MAX];
int testcase, n, m = 0;

// mCn - 전체 m개에서 n개 뽑기
long long dp(int n, int m) {
    if (m == 0 || m == n) return 1;

    // 메모리제이션 - 필요 없는 연산을 줄여줌
    long long &ret = memo[n][m];
    if (ret != -1) return ret;

    return ret = dp(n - 1, m - 1) + dp(n - 1, m);
}

int main() {
    // 테스트 케이스 입력
    cin >> testcase;

    // 각각의 테스트 케이스 마다 n과 m 입력 받기
    for (int i = 0; i < testcase; ++i) {
        memset(memo, -1, sizeof(memo)); 

        cin >> n >> m;
        cout << dp(m, n) << "\n";
    }

    return 0;
}