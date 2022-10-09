#include <iostream>
#include <algorithm>

using namespace std;

char board[51][51];

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char color; cin >> color;
            board[i][j] = color;
        }
    }

    int answer = 1e9;

    for (int x = 0; x <= n - 8; ++x) {
        for (int y = 0; y <= m - 8; ++y) { // 8*8
            int cnt = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (i % 2 == j % 2) {
                        if (board[x + i][y + j] == 'W') cnt++;
                    } else {
                        if (board[x + i][y + j] == 'B') cnt++;
                    }
                }
            }

            answer = min(answer, min(cnt, 64 - cnt));           
        }
    }

    cout << answer <<'\n';


    return 0;
}