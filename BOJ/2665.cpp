#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 다익스트라

using namespace std;

int n;
int board[51][51];
bool visited[51][51];
int movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dijkstra(int x, int y) {
    priority_queue< pair<int, pii> > pq;
    pq.push( {-0, {x, y}});
    visited[x][y] = true;

    while(!pq.empty()) {
        int hereX = pq.top().second.first;
        int hereY = pq.top().second.second;
        int hereCnt = -pq.top().first;

        pq.pop();

        if(hereX == n - 1 && hereY == n - 1) return hereCnt;

        for(int i = 0; i < 4; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= n) continue;
            if(visited[thereX][thereY]) continue;

            if(board[thereX][thereY]) pq.push({-hereCnt, {thereX, thereY}});
            else pq.push({-(hereCnt + 1), {thereX, thereY}});

            visited[thereX][thereY] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));
    
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;

        for(int j = 0; j < n; ++j) {
            board[i][j] = s[j] - '0';
        }
    }

    cout << dijkstra(0, 0) << '\n';
    
    return 0;
}