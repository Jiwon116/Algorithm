#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

struct ST{
    int x, y;
    char color;
};

int n;
char board[101][101];
bool vis[101][101] = {false, };
int movement[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

void bfs(int x, int y, char color) {
    queue<ST> q;

    q.push({x, y, color});
    vis[x][y] = true;

    while(!q.empty()) {
        int here_x = q.front().x;
        int here_y = q.front().y;
        char here_color = q.front().color;

        //cout << "x = " << here_x << ", y = " << here_y << ", color = " << here_color << '\n';

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];
            char there_color = board[there_x][there_y];

            if(there_x < 0 || there_x >= n || there_y < 0 || there_y >= n) continue;
            if(vis[there_x][there_y]) continue;
            if(there_color != here_color) continue;

            q.push({there_x, there_y, there_color});
            vis[there_x][there_y] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    int count = 0;
    // 적록색약이 아닐 경우 먼저 bfs 호출
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!vis[i][j]) {
                bfs(i, j, board[i][j]);
                count++;
            }
        }
    }

    // 적록색약일 경우 G를 R로 변경 후 bfs 호출
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    int RGcount = 0;
    memset(vis, false, sizeof(vis)); // 방문 초기화

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!vis[i][j]) {
                bfs(i, j, board[i][j]);
                RGcount++;
            }
        }
    }

    cout << count << " " << RGcount << '\n';
    
    return 0;
}