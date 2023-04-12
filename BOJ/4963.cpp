#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int w, h; // 지도의 너비와 높이
int board[51][51];
int vis[51][51] = {false , };

int bfs(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    
    while(!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;

        q.pop();

        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                int there_x = here_x + i;
                int there_y = here_y + j;

                if(there_x < 0 || there_x >= h || there_y < 0 || there_y >= w) continue;
                if(vis[there_x][there_y]) continue;
                if(board[there_x][there_y] == 0) continue;

                q.push({there_x, there_y});
                vis[there_x][there_y] = true;
            }
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(1) {
        cin >> w >> h;

        if(w == 0 && h == 0) break; // w, h가 0이면 종료

        int answer = 0;
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                if(board[i][j] == 1 && vis[i][j] == false) {
                    answer += bfs(i, j);
                    vis[i][j] = true;
                }

            }
        }

        cout << answer << '\n';
    }
    
    return 0;
}