#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

struct KNIGHT {
    int x, y, count;
};

int t, l; // t : 테스트 개수 / l : 체스판 크기
int x, y, xx, yy; // 나이트의 현재 위치 & 갈 위치
int movement[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}, {2, -1}, {1, -2}};

int bfs(int x, int y) {
    
    int board[301][301];
    queue<KNIGHT> q;
    int answer = 0;

    memset(board, 0, sizeof(board));

    q.push({x, y, 0});
    board[x][y] = 1;

    while(!q.empty()) {
        int here_x = q.front().x;
        int here_y = q.front().y;
        int here_count = q.front().count;

        q.pop();

        if(here_x == xx && here_y == yy) {
            answer = here_count;
            break;
        }

        for(int i = 0; i < 8; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];
            int there_count = here_count + 1;

            if(there_x >= l || there_x < 0 || there_y >= l || there_y < 0) continue;
            if(board[there_x][there_y] == 1) continue;

            q.push({there_x, there_y, there_count});
            board[there_x][there_y] = 1;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    while(t--) {
        cin >> l >> x >> y >> xx >> yy;

        cout << bfs(x, y) << '\n';
    }
    
    return 0;
}