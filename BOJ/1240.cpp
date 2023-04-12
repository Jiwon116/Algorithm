#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector<pii> adj[1001];
int visited[1001];

int bfs(int start, int end){
    memset(visited, -1, sizeof(visited));

    queue<int> q;
    q.push(start);
    visited[start] = 0;

    while(!q.empty()) {
        int here = q.front();
        q.pop();

        for (auto there : adj[here]) {
            if(visited[there.first] != -1) continue; // 이미 방문함
            visited[there.first] = visited[here] + there.second;
            q.push(there.first);
        }
    }

    return visited[end];
}

int main() {

    cin >> n >> m;

    for(int i = 1; i < n; ++i) {
        int from, to, value; cin >> from >> to >> value;
        adj[from].push_back({to, value});
        adj[to].push_back({from, value});
    }

    for(int i = 0 ; i < m; ++i) {
        int from, to; cin >> from >> to;
        cout << bfs(from, to) << '\n';
    }

    return 0;
}