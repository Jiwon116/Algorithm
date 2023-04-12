#include <iostream>
#define MAX 31

using namespace std;

int dp[MAX][MAX];
int R, C, W = 0;
int answer = 0;

int main() {
    cin >> R >> C >> W;

    for(int i = 1; i < MAX; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    for (int i = 0; i < W; ++i) {
        for (int j = 0; j <= i; ++j) {
            answer += dp[R+i][C+j];
        }
    }

    cout << answer << "\n";

    return 0;
}