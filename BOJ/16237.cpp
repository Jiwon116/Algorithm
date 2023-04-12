#include <iostream>

using namespace std;

int a, b, c, d, e, total = 0;

int main() {

    cin >> a >> b >> c >> d >> e;

    // 5kg는 무조건 바구니 1개씩 할당
    if (e > 0) {
        total += e;
    }

    // 4kg는 1kg랑 같이 바구니 1개씩 할당받을 수 있음.
    // 1kg이 없다면 4kg 하나 당 바구니 1개
    if (d > 0) {
        total += d;
        a = a - d;
    }

    // 3kg은 2kg과 같이 바구니 1개씩 할당받을 수 있음.
    // 2kg이 없다면 1kg 2개로 채워넣음
    if (c > 0) {
        total += c;
        int temp = min(b, c);
        b = b - temp;
        c = c - temp;
        if (c > 0) {
            a = a - 2 * c;
        }
    }

    // 남은 2kg은 2개 당 바구니 1개씩 할당받을 수 있음.
    // 1kg이 남았다면 1개씩 함께 넣을 수 있음.
    // 넣고 남은 2kg가 1개라면....
    if (b > 0) {
        if (b % 2 == 0) {
            total = total + (b/2);
        } else {
            total = total + (b/2) + 1;
        }
        a = a - (b/2) - 3 * (b % 2);
    }

    // 남은 1kg은 5개 당 바구니 1개씩 할당받을 수 있음.
    // 5개가 아니라도 바구니 1개에 넣어야 함
    if (a > 0) {
        if (a % 5 == 0) {
            total = total + (a/5);
        } else {
            total = total + (a/5) + 1;
        }
    }

    cout << total << "\n";

    return 0;
}