#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, k;

int bfs(int n, int k, int time) {
    queue<pii> q;
    bool vis[200002] = {false, };

    q.push({n, time});
    vis[n] = true;
    
    while(!q.empty()) {
        int here = q.front().first;
        int here_time = q.front().second;

        q.pop();

        if (here == k) return here_time;

        if(here - 1 >= 0 && !vis[here - 1]) {
            q.push({here - 1, here_time + 1});
            vis[here - 1] = true;
        }

        if(here + 1 < 100001 && !vis[here + 1]) {
            q.push({here + 1, here_time + 1});
            vis[here + 1] = true;
        }

        if(here != 0 && here * 2 < 100001 * 2 && !vis[here * 2]) {
            q.push({here * 2, here_time + 1});
            vis[here * 2] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> k;

    cout << bfs(n, k, 0) << '\n';
    
    return 0;
}