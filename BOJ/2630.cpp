#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 분할 정복

using namespace std;

int board[129][129];
int blue, white;

void solution(int n, int x, int y) {

    int color = board[x][y];

    for(int i = x; i < x + n; ++i) {
        for(int j = y; j < y + n; ++j) {
            if(color != board[i][j]) {
                solution(n / 2, x, y);
                solution(n / 2, x, y + n / 2);
                solution(n / 2, x + n / 2, y);
                solution(n / 2, x + n / 2, y + n / 2);

                return;
            }
        }
    }

    if(color) blue++;
    else white++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) 
            cin >> board[i][j];
    }

    solution(n, 0, 0);

    cout << white << '\n' << blue << '\n';
    
    return 0;
}