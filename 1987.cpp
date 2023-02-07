#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// dfs + 백트래킹

using namespace std;

int r, c;
char board[21][21];
bool visited[26];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int answer;

void dfs(int x, int y, int dist) {
    answer = max(dist, answer);
    visited[board[x][y] - 'A'] = true;

    for(int i = 0; i < 4; ++i) {
        int thereX = x + movement[i][0];
        int thereY = y + movement[i][1];

        if(thereX < 0 || thereX >= r || thereY < 0 || thereY >= c) continue;
        if(visited[board[thereX][thereY] - 'A']) continue;

        dfs(thereX, thereY, dist + 1);
    }

    visited[board[x][y] - 'A'] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> c;
    
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j)
            cin >> board[i][j];
    }

    dfs(0, 0, 1);

    cout << answer << '\n';
    
    return 0;
}