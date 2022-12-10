#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
int board[9][9];
bool vis[9][9];
int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> answer;

void bfs(int x, int y) {
    queue<pii> q;

    q.push({x, y});
    vis[x][y] = true;
    
    while(!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];

            if(there_x < 0 || there_x >= n || there_y < 0 || there_y >= m) continue;
            if(vis[there_x][there_y]) continue;
            if(board[there_x][there_y] == 1) continue;

            vis[there_x][there_y] = true;
            q.push({there_x, there_y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> board[i][j];
            board[i][j] = board[i][j];
        }
    }

    vector<int> v(n * m, 0);
    for(int i = 0; i < 3; ++i) v[i] = 1;

    do {
        // 벽을 세울 수 있는지 확인
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(v[i * m + j] == 1 && board[i][j] == 0) {
                    cnt++;
                }
            }
        }

        // 벽이 3개면 board[i][j] 1로 변경
        if(cnt == 3) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(v[i * m + j] == 1 && board[i][j] == 0) {
                        board[i][j] = 1;
                    }
                }
            }

            memset(vis, false, sizeof(vis));
            // 바이러스 퍼트리기
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(board[i][j] == 2 && vis[i][j] == false) {
                        bfs(i, j);
                    }
                }
            }
            
            int ans = 0;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(board[i][j] == 0 && vis[i][j] == false) ans++;
                }
            }

            answer.push_back(ans);

            // bfs 탐색 후 다시 board[i][j]를 원래대로 복구
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    if(v[i * m + j] == 1 && board[i][j] == 1) {
                        board[i][j] = 0;
                    }
                }
            }
        }

    } while(next_permutation(v.rbegin(), v.rend()));

    cout << *max_element(answer.begin(), answer.end()) << '\n';
    
    return 0;
}