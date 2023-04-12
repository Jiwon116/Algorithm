#include <iostream>
#define MAX 10001

using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool check[MAX] = {0, };
    int sum, n;

    for (int i = 1; i < MAX; i++) {
        sum = 0;
        n = i;

        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        sum += i;

        if (sum < 10001) {
            check[sum] = true;
        }
    }

    for (int i = 1; i < MAX; i++) {
        if (!check[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}