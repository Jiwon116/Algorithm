#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int cnt = n / 5;
    int res = n % 5;

    while (cnt > 0 && res % 2 != 0) {
        cnt --;
        res += 5;
    }

    if (res % 2 == 0)
        cout << cnt + res / 2 << "\n";
    else
        cout << -1 << "\n";

    return 0;
}