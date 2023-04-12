#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 구현 + 시뮬레이션

using namespace std;

int n, m, r, c, d;
int board[51][51];
int visited[51][51] = {0, };
int movement[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // 북 동 남 서

void dfs(int x, int y, int dir, int cnt) {
    for(int i = 0; i < 4; ++i) {
        int thereD = (dir + 3 - i) % 4;
        int thereX = x + movement[thereD][0];
        int thereY = y + movement[thereD][1];

        if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= m || board[thereX][thereY] == 1) continue;

        if(visited[thereX][thereY] == 0 && board[thereX][thereY] == 0){
            visited[thereX][thereY] = 1;
            dfs(thereX, thereY, thereD, cnt + 1);
        }
    }

    int beforeD = dir + 2 < 4 ? dir + 2 : dir - 2;
    int beforeX = x + movement[beforeD][0];
    int beforeY = y + movement[beforeD][1];

    if(beforeX >= 0 && beforeX < n && beforeY >= 0 && beforeY < m) {
        if(board[beforeX][beforeY] == 0) dfs(beforeX, beforeY, dir, cnt);
        else {
            cout << cnt << '\n';
            exit(0);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> r >> c >> d;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];
    }

    visited[r][c] = 1;

    dfs(r, c, d, 1);
    
    return 0;
}