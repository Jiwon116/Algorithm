#include <iostream>
#include <string>

using namespace std;

int main() {
    string s; cin >> s;

    for (auto e : s) {
        if ('a' <= e && e <= 'z') cout << char(e - 'a' + 'A');
        else cout << char(e - 'A' + 'a');
    }

    return 0;
}