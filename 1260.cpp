#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;
vector<int> vec[1001];
bool visited[1001];
vector<int> b;

void dfs(int root) {
    visited[root] = true;
    cout << root << " ";

    for(auto e : vec[root]) {
        if(visited[e]) continue;
        dfs(e);
    }
}

void bfs(int root) {
    queue<int> q;
    q.push(root);
    visited[root] = true;

    while(!q.empty()) {
        int here = q.front();
        cout << here << " ";
        q.pop();

        for(int there : vec[here]) {
            if(visited[there]) continue;
            visited[there] = true;
            q.push(there);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, v; cin >> n >> m >> v;

    for(int i = 0; i < m; ++i) {
        int first, second; cin >> first >> second;
        vec[first].push_back(second);
        vec[second].push_back(first);
    }

    for(int i = 1; i <= n; ++i) {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(v);

    memset(visited, false, sizeof(visited));

    cout << '\n';

    bfs(v);
    
    return 0;
}