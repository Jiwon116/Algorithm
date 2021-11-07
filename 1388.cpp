#include <iostream>
#include <string.h>
#include <queue>
#define MAX 101

using namespace std;

int n, m = 0;
char ground[MAX][MAX];
bool visited[MAX][MAX];

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        // 가로 -> 오른쪽
        if (ground[hereX][hereY] == '-') {

            int thereX = hereX;
            int thereY = hereY + 1;

            if (thereX < n && thereY < m && ground[hereX][hereY] == ground[thereX][thereY]) {
                q.push({thereX, thereY});
                visited[thereX][thereY] = true;
            }
        }
        else { // 세로 -> 아래
            int thereX = hereX + 1;
            int thereY = hereY;

            if (thereX < n && thereY < m && ground[hereX][hereY] == ground[thereX][thereY]) {
                q.push({thereX, thereY});
                visited[thereX][thereY] = true;
            }
        }
        
    }

}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> ground[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    int answer = 0;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(visited[i][j] == false) {
                bfs(i, j);
                ++answer;
            }
        }
    }

    cout << answer << "\n";


    return 0;
}