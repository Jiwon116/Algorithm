#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 백트래킹

using namespace std;

int n;
bool flag = false;

void backtrack(string str, int cnt) {
    if(flag) return;

    for(int i = 1; i <= (str.size() / 2); ++i) {
        if(str.substr(str.size() - i, i) == str.substr(str.size() - (i * 2), i)) return;
    }

    if(cnt == n) {
        flag = true;
        cout << str << '\n';
    }

    backtrack(str + "1", cnt + 1);
    backtrack(str + "2", cnt + 1);
    backtrack(str + "3", cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    backtrack("", 0);
    
    return 0;
}