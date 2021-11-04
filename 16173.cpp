#include <iostream>
#include <string.h>
#include <queue>
#define MAX_ROUND 3 + 1

using namespace std;
int n; //게임장 크기
int board[MAX_ROUND][MAX_ROUND]; //보드판 숫자
bool visited[MAX_ROUND][MAX_ROUND]; // 보드판 크기만큼 방문 여부 체크하기! -> 배열로 선언하기

void bfs(int x, int y) {
    memset(visited, false, sizeof(visited)); // 방문 여부 초기화

    queue<pair<int, int>> q;
    q.push({x, y}); // 처음 시작점 큐에 넣기
    visited[x][y] = true;

    while(!q.empty()) {
        int hereX = q.front().first;
        int hereY = q.front().second;
        q.pop();

        if(board[hereX][hereY] == -1) {
            cout << "HaruHaru\n";
            return;
        }


        // 1. 오른쪽 가는 애
        int thereX = hereX;
        int thereY = hereY + board[hereX][hereY];

        if(thereX < n && thereY < n && (visited[thereX][thereY] == false)) {
            q.push({thereX, thereY});
            visited[thereX][thereY] = true;
        }

        // 2. 아래쪽 가는 애
        thereX = hereX + board[hereX][hereY];
        thereY = hereY;

        if(thereX < n && thereY < n && (visited[thereX][thereY] == false)) {
            q.push({thereX, thereY});
            visited[thereX][thereY] = true;
        }
    }

    cout << "Hing\n";
    return;

}

int main() {

    cin >> n;

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    bfs(0, 0); //처음 시작점이 0, 0임

    return 0;
}