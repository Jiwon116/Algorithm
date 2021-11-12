// 1032
#include <iostream>
#include <string.h>
#define MAX 51

using namespace std;

int n = 0;
string str[MAX];

int main() {

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str[i];
    }

    for (int i = 0; i < str[0].length(); ++i) {
        for (int j = 1; j < n; ++j) {
            if (str[0][i] != str[j][i]) {
                str[0][i] = '?';
                break;
            }
        }
        cout << str[0][i];
    }

    return 0;
}