#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
int board[101][101];
bool visited[101][101];
int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int x, int y) {
    memset(visited, false, sizeof(visited));

    priority_queue< pair<int, pii> > pq;
    pq.push({ 0, {x, y}});
    visited[x][y] = true;

    while(!pq.empty()) {
        int hereX = pq.top().second.first;
        int hereY = pq.top().second.second;
        int cnt = -pq.top().first;

        if(hereX == n - 1 && hereY == m - 1) return cnt;

        pq.pop();

        for (int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= m) continue;

            if(visited[thereX][thereY]) continue;

            if(board[thereX][thereY] == 1) pq.push({-(cnt + 1), {thereX, thereY}});
            else pq.push({-cnt, {thereX, thereY}});
            
            visited[thereX][thereY] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;

        for(int j = 0; j < m; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    cout << bfs(0, 0) << '\n';

    return 0;
}