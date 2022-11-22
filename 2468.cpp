#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n; // 지역의 크기
int board[101][101];
int vis[101][101] = {false, };
int movement[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});

    while(!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];

            if(there_x < 0 || there_x >= n || there_y < 0 || there_y >= n) continue;
            if(vis[there_x][there_y]) continue; 

            q.push({there_x, there_y});
            vis[there_x][there_y] = true;
        }
    }

    return 1;
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

    int max_height = 0;
    int ans[101] = {0,};
    int max_ans = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            max_height = max(max_height, board[i][j]);
        }
    }

    for(int k = 0; k <= max_height; ++k) {
        memset(vis, false, sizeof(vis));

        // 높이가 k 이하인 부분들 -> 안전하지 않은 영역 -> vis 처리로 가지 못하게 함
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] <= k) vis[i][j] = true;
            }
        }


        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                // board에서 bfs 함수를 호출한 횟수 파악 -> 안전한 영역의 개수
                if(board[i][j] > k && vis[i][j] == false) {
                    ans[k] += bfs(i, j);
                }
            }
        }
    }

    for(int i = 0; i <= max_height; ++i) {
        max_ans = max(ans[i], max_ans);
    }

    cout << max_ans << '\n';
    
    return 0;
}