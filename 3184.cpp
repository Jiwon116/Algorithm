#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, total_s = 0, total_w = 0;
int board[251][251];
bool visited[251][251];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = true;

    int s = 0, w = 0;

    if(board[x][y] == 'o') ++s;
    else if(board[x][y] == 'v') ++w;

    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= m) continue;
            if(visited[thereX][thereY] || board[thereX][thereY] == '#') continue;

            if(board[thereX][thereY] == 'o') ++s;
            if(board[thereX][thereY] == 'v') ++w;

            q.push({thereX, thereY});
            visited[thereX][thereY] = true;
        }
    }

    if(s > w) total_w -= w;
    else total_s -= s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j){
            cin >> board[i][j];
            if(board[i][j] == 'o') ++total_s;
            else if (board[i][j] == 'v') ++total_w;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] != '#' && !visited[i][j]) bfs(i, j);
        }
    }

    cout << total_s << " " << total_w << '\n';
    
    return 0;
}