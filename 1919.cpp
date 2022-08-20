#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    int alpha1[26] = {0, }, alpha2[26] = {0, };
    int cnt = 0;

    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); ++i) alpha1[s1[i] - 'a']++;
    for(int i = 0; i < s2.length(); ++i) alpha2[s2[i] - 'a']++;

    for(int i = 0; i < 26; i++) {
        if(alpha1[i] != alpha2[i]) cnt += abs(alpha1[i] - alpha2[i]);
    }

    cout << cnt << '\n';

    return 0;
}