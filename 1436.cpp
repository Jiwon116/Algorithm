#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;

    int count = 1;
    int num = 666;

    while (count != n) {
        num++;

        string s_num = to_string(num);

        for (int i = 0; i < s_num.length() - 2; ++i) {
            if(s_num[i] == '6' && s_num[i + 1] == '6' && s_num[i + 2] == '6') {
                count++;
                break;
            }
        }
    }

    cout << num << '\n';

    return 0;
}