#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, r1, c1, r2, c2;
bool visited[201][201];
int movement[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};

int bfs(int x, int y) {
    queue< pair<pii, int> > q;
    q.push({{x, y}, 0});
    visited[x][y] = true;

    while(!q.empty()) {
        int hereX = q.front().first.first;
        int hereY = q.front().first.second;
        int cnt = q.front().second;

        q.pop();

        if(hereX == r2 && hereY == c2) return cnt;

        for(int i = 0; i < 6; ++i) {
            int thereX = hereX + movement[i][0];
            int thereY = hereY + movement[i][1];

            if(thereX < 0 || thereX >= n || thereY < 0 || thereY >= n) continue;
            if(visited[thereX][thereY]) continue;

            q.push({{thereX, thereY}, cnt + 1});
            visited[thereX][thereY] = true;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(visited, false, sizeof(visited));
    
    cin >> n >> r1 >> c1 >> r2 >> c2;

    cout << bfs(r1, c1) << '\n';
    
    return 0;
}