#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;

    int cnt = 0;
    int num = 0;

    while(num < n) {
        num++;

        if (num < 100) cnt++;
        else {
            string s_num = to_string(num);

            if((s_num[0] - s_num[1]) == (s_num[1] - s_num[2])) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}