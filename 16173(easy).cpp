#include <iostream>
#include <cstring>
#include <queue>

#define MAX_BOARD 3 + 1

using namespace std;

int n; // 게임 구역의 크기
int board[MAX_BOARD][MAX_BOARD]; // 게임판
bool visited[MAX_BOARD][MAX_BOARD];
int movement[2][2] = {{0, 1}, {1, 0}};
// 4방향으로 가고싶을때는
// int movement[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void bfs(int x, int y) {
    memset(visited, false, sizeof(visited)); // 방문 정보 초기화

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true; 

    while (!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        if (board[hereX][hereY] == -1) {
            cout << "HaruHaru\n";
            return;
        }
        // 인접하다 : 오른쪽 또는 아래
        for (int i = 0; i < 2; ++i) {
            int thereX = hereX + movement[i][0] * board[hereX][hereY];
            int thereY = hereY + movement[i][1] * board[hereX][hereY];

            if (thereX < 0 || thereX >= n || thereY < 0 || thereY >= n) continue;
            if (visited[thereX][thereY]) continue;
            visited[thereX][thereY] = true;
            q.push({thereX, thereY});
        }
    }

    cout << "Hing\n";
    return;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    bfs(0, 0);

    return 0;
}