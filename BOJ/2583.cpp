#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int m, n, k;
int board[101][101];
bool vis[101][101] = {false, };
int movement[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(int x, int y, int area) {
    queue<pii> q;
    int max_area = 1;

    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()) {
        int here_x = q.front().first;
        int here_y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; ++i) {
            int there_x = here_x + movement[i][0];
            int there_y = here_y + movement[i][1];

            if(there_x < 0 || there_x >= m || there_y < 0 || there_y >= n) continue;
            if(vis[there_x][there_y]) continue;

            q.push({there_x, there_y});
            max_area++;
            vis[there_x][there_y] = true;
        }
    }

    return max_area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> n >> k;

    for(int i = 0; i < k; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        for(int b = y1; b < y2; ++b) {
            for(int a = x1; a < x2; ++a) {
                vis[b][a] = true;
            }
        }
    }

    int count = 0;
    vector<int> width;

    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!vis[i][j]) {
                width.push_back(bfs(i, j, 0));
                count++;    // 총 영역의 개수 = bfs 함수가 호출된 횟수
            }
        }
    }

    sort(width.begin(), width.end());

    cout << count << '\n';
    for(auto e : width) {
        cout << e << " ";
    }
    cout << '\n';

    return 0;
}