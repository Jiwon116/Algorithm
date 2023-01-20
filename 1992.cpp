#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int board[65][65];

void solution(int n, int x, int y) {
    if(n == 1) {
        cout << board[x][y];
        return;
    }

    bool is_zero = true;
    bool is_one = true;

    for(int i = x; i < x + n; ++i) {
        for(int j = y; j < y + n; ++j) {
            if(board[i][j]) is_zero = false;
            else is_one = false;
        }
    }

    if(is_zero) cout << 0;
    else if(is_one) cout << 1;
    else {
        cout << "(";
        solution(n / 2, x, y);
        solution(n / 2, x, y + n / 2);
        solution(n / 2, x + n / 2, y);
        solution(n / 2, x + n / 2, y + n / 2);
        cout << ")";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;

        for(int j = 0; j < n; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    solution(n, 0, 0);
    
    return 0;
}