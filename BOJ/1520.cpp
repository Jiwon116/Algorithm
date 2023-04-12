#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
int board[501][501];
int visited[501][501];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int x, int y) {
    if(x == n - 1 && y == m - 1) return 1;
    if(visited[x][y] != -1) return visited[x][y];
    
    visited[x][y] = 0;

    for(int i = 0; i < 4; ++i) {
        int thereX = x + movement[i][0];
        int thereY = y + movement[i][1];

        if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= m) continue;

        if(board[x][y] > board[thereX][thereY]) visited[x][y] += dfs(thereX, thereY);
    }

    return visited[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
            cin >> board[i][j];

    cout << dfs(0, 0);
    
    return 0;
}