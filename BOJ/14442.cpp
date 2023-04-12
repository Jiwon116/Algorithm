#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

struct WELL {
    int x, y, block, cnt;
};

int n, m, k, answer = 0;
int board[1001][1001];
bool visited[1001][1001][11];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int bfs() {
    queue<WELL> q;
    q.push({0, 0, 0, 1});
    visited[0][0][0] = true;

    while(!q.empty()) {
        int hereX = q.front().x;
        int hereY = q.front().y;
        int hereBlock = q.front().block;
        int hereCnt = q.front().cnt;

        q.pop();

        if(hereX == n - 1 && hereY == m - 1) return hereCnt;

        for(int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= m) continue;

            // 벽인데 아직 안 뚫음 && 길인데 방문 안함
            if(board[thereX][thereY] == 1 && hereBlock < k && !visited[thereX][thereY][hereBlock + 1]) {
                q.push({thereX, thereY, hereBlock + 1, hereCnt + 1});
                visited[thereX][thereY][hereBlock + 1] = true;
            } else if (board[thereX][thereY] == 0 && !visited[thereX][thereY][hereBlock]) {
                q.push({thereX, thereY, hereBlock, hereCnt + 1});
                visited[thereX][thereY][hereBlock] = true;
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));
    
    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        for(int j = 0; j < m; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    cout << bfs() << '\n';

    return 0;
}