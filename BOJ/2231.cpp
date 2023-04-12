// 완전탐색 (브루트포스)
#include <iostream>

using namespace std;

int n;
int ans = 0;

int main() {
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int sum = 0;
        int num = i;

        // 자리수마다 더하기
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }

        if (sum + i == n) {
            ans = i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}