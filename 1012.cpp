#include <iostream>
#include <string.h>
#include <queue>
#define MAX 51

using namespace std;

int t, m, n, k = 0;
int ground[MAX][MAX];
bool visited[MAX][MAX];
int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        // 4방향으로 움직이기
        for (int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            // 밭 범위 밖으로 나가지 않게!
            if (thereX < 0 || thereX >= n || thereY < 0 || thereY >= m) continue;

            // 배추인지 아닌지 확인! -> 땅이면 pass
            if(ground[thereX][thereY] == 0) continue;

            // 방문한 배추인지 확인!
            if(visited[thereX][thereY]) continue;

            q.push({thereX, thereY});
            visited[thereX][thereY] = true;
        }
    }
}

int main() {

    // 테스트 케이스 입력받기
    cin >> t;

    while(t--) {
        // 테스트 케이스마다 밭의 정보 초기화
        memset(ground, 0 , sizeof(ground));
        memset(visited, false, sizeof(visited));

        // 밭의 가로와 세로 입력받기
        cin >> m >> n;

        // 배추가 심어진 개수
        cin >> k;

        while(k--) {
            // 배추의 위치 입력받기
            int x, y;
            cin >> x >> y;
            ground[y][x] = 1;
        }

        int answer = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0 ; j < m; ++j) {
                if (ground[i][j] == 1 && visited[i][j] == false) {
                    bfs(i, j);
                    ++answer;
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}