#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string s;
    int is_minus = 1;
    int num = 0, sum = 0;

    cin >> s;

    for(int i = 0; i < s.length(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') num = (num * 10) + (s[i] - '0'); // string -> int 으로 변환
        else {
            sum += is_minus * num;

            if(s[i] == '-') is_minus = -1;

            num = 0;
        }
    }
    
    sum += is_minus * num;

    cout << sum << '\n';
    
    return 0;
}