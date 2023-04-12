#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

struct TOMATO {
    int x, y, day;
};

using namespace std;

int m, n;
int board[1001][1001];
int vis[1001][1001];
queue<TOMATO> q;
int movement[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs() {
    int max_day = 0;
    while(!q.empty()) {
        int here_x = q.front().x;
        int here_y = q.front().y;
        int here_day = q.front().day;
        max_day = max(max_day, here_day);
        q.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];

            if(there_x < 0 || there_x >= n || there_y < 0 || there_y >= m) continue;
            if(vis[there_x][there_y] || board[there_x][there_y] != 0) continue;
            vis[there_x][there_y] = true;
            q.push({there_x, there_y, here_day + 1});
        }
    }

    return max_day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 1) { // 익은 토마토들을 queue에 담아줌
                q.push({i, j, 0});
                vis[i][j] = true;   // queue에 담았으니까 방문함
            }
        }
    }

    int answer = 0;

    answer = bfs();

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(board[i][j] == 0 && vis[i][j] == false) answer = -1;
        }
    }

    cout << answer;
    
    return 0;
}