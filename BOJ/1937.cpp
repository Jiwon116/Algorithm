#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, answer;
int board[501][501];
int visited[501][501];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs(int x, int y) {
    if(visited[x][y] != -1) return visited[x][y];

    visited[x][y] = 1;

    for(int i = 0; i < 4; ++i) {
        int thereX = x + movement[i][0];
        int thereY = y + movement[i][1];

        if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= n) continue;

        if(board[thereX][thereY] > board[x][y]) visited[x][y] = max(visited[x][y], dfs(thereX, thereY) + 1);
    }

    return visited[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, -1, sizeof(visited));
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer << '\n';
    
    return 0;
}