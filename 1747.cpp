#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

bool arr[2000001];

void isPrime() {
    for(int i = 2; i < 2000001; ++i) arr[i] = true;

    arr[0] = false;
    arr[1] = false;

    for(int i = 2; i < 2000001; ++i) {
        for(int j = 2; j * j <= i; ++j) {
            if(i % j == 0) {
                arr[i] = false;
                break;
            }
        }
    }
}

bool isPalindrome(int num) {
    string s = to_string(num);
    for(int i = 0; i < s.size() / 2; ++i){
        if(s[i] != s[s.size() - 1 - i]) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    isPrime();

    for(int i = n; i <= 2000001; ++i) {
        if(arr[i] && isPalindrome(i)) {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}