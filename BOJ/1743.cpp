#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, k;
int board[101][101] = {0, };
bool visited[101][101];
int movement[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt = 1;

void bfs(int x, int y) {
    queue<pii> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX > n || thereY < 0 || thereY > m) continue;

            if(board[thereX][thereY] && !visited[thereX][thereY]) {
                q.push({thereX, thereY});
                visited[thereX][thereY] = true;
                cnt++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));

    cin >> n >> m >> k;

    for(int i = 0; i < k; ++i) {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(board[i][j] == 1 && !visited[i][j]) {
                bfs(i, j);
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}