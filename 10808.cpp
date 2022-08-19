#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    string s;
    int arr[26] = {0, };
    int answer[26] = {0, };

    // for(int i = 0; i < 26; ++i) {
    //     arr[i] = i + 97;
    // }

    cin >> s;

    // for(int i = 0; i < s.length(); ++i) {
    //     for(int j = 0; j < 26; ++j) {
    //         if (s[i] == arr[j]) {
    //             answer[j]++;
    //         }
    //     }
    // }

    // for (char c : s) answer[c - 'a']++;
    
    map<char, int> m;
    for (char c : s) {
        if (m.find(c) == m.end()) m[c] = 1;
        else m[c] += 1;
    }

    for (int c = 'a'; c <= 'z'; ++c) {
        cout << m[(char)c] << " ";
    }
    // for(int i: answer) cout << i << " ";

    return 0;
}