#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

char board[51][51];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 'o') {
                int index = i;
                board[i][j] = '.';
                while(board[++index][j] == '.' && i != n) ;
                board[index - 1][j] = 'o';
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}