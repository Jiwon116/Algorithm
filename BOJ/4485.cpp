#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 2차원 다익스트라

using namespace std;

int n, cnt;
int board[126][126];
int dist[126][126];
int movement[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dijkstra() {
    priority_queue< pair<int, pii> > pq;

    pq.push({-board[0][0], {0, 0}});
    dist[0][0] = board[0][0];

    while (!pq.empty()) {
        int here_x = pq.top().second.first;
        int here_y = pq.top().second.second;
        int here_cost = -pq.top().first;

        pq.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];
            int there_cost = here_cost + board[there_x][there_y];
            
            if (there_x < 0 || there_x >= n || there_y < 0 || there_y >= n) continue;
            if (dist[there_x][there_y] <= there_cost) continue;

            dist[there_x][there_y] = there_cost;
            pq.push({-there_cost, {there_x, there_y}});
        }
    }

    cout << "Problem " << cnt << ": " << dist[n-1][n-1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        cnt++;

        cin >> n;
        
        if(n == 0) break;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                dist[i][j] = 1e9;
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        }

        dijkstra();
    }
    
    return 0;
}