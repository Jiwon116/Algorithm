#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 201
#define INF 1e9

using namespace std;

int k; //  이동할 수 있는 횟수
int w, h; // 가로, 세로

int board[MAX][MAX];

struct q_STR {
    int move_cnt;
    int x;
    int y;
    int horse; // 말 처럼 이동한 횟수
};

int movement[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int horse_move[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
bool vis[MAX][MAX][31];

int bfs(int x, int y) {
    queue<q_STR> q;
    q.push({0, x, y, 0});

    vis[x][y][0] = true;

    while (!q.empty()) {
        int nx = q.front().x;
        int ny = q.front().y;
        int nc = q.front().move_cnt;
        int nh = q.front().horse;
        q.pop();

        if (nx == h - 1 && ny == w - 1) return nc;

        // 1. 말처럼 이동하기
        for (int i = 0; i < 8 && nh < k; ++i) {
            int tx = nx + horse_move[i][0];
            int ty = ny + horse_move[i][1];
            int tc = nc + 1;

            if (tx < 0 || ty < 0 || tx >= h || ty >= w || vis[tx][ty][tc] || board[tx][ty] == 1) continue;

            if (i <= 1) {
                if (board[nx - 1][ny] == 1 || board[nx - 2][ny] == 1) continue;
            } else if (i <= 3) {
                if (board[nx][ny + 1] == 1 || board[nx][ny + 2] == 1) continue;
            } else if (i <= 5) {
                if (board[nx + 1][ny] == 1 || board[nx + 2][ny] == 1) continue;
            } else {
                if (board[nx][ny - 1] == 1 || board[nx][ny - 2] == 1) continue;
            }

            vis[tx][ty][tc] = true;
            q.push({tc, tx, ty, nh + 1});
        }

        // 2. 뚜벅이(상하좌우)
        for (int i = 0; i < 4; ++i) {
            int tx = nx + movement[i][0];
            int ty = ny + movement[i][1];
            int tc = nc + 1;

            if (tx < 0 || ty < 0 || tx >= h || ty >= w || vis[tx][ty][tc] || board[tx][ty] == 1) continue;

            vis[tx][ty][tc] = true;
            q.push({tc, tx, ty, nh});
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> k >> w >> h;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> board[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    cout << bfs(0, 0) << "\n";

    return 0;
}