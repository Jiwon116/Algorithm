#include <iostream>

using namespace std;

int main() {
    
    int n; cin >> n;
    long long sum = 0;
    int digit = 0;
    while (n--) {
        char c; cin >> c;
        if ('0' <= c && c <= '9') {
            digit = digit * 10 + (c - '0');
        } else {
            sum += digit;
            digit = 0;
        }
    }

    sum += digit;
    cout << sum << "\n";

    return 0;
}