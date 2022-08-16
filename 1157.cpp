#include <iostream>

using namespace std;

int main() {
    string s;
    int a[26] = {0, };
    int cnt = 0;

    cin >> s;

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] < 97) a[s[i] - 65]++;
        else a[s[i] - 97]++;
    }

    int max = 0, max_indx = 0;

    for (int i = 0; i < 26; ++i) {
        if (max < a[i]) {
            max = a[i];
            max_indx = i;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (max == a[i]) cnt++;
    }
    
    if (cnt > 1) cout << "?\n";
    else cout << (char)(max_indx + 65) << '\n';

    return 0;
}