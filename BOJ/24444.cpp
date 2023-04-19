#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// bfs

using namespace std;

vector<int> graph[100001];
bool visited[1000001];
int answer[1000001];
int cnt = 0;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    cnt++;
    answer[start] = cnt;

    while(!q.empty()) {
        int here = q.front();
        q.pop();


        for(int i = 0; i < graph[here].size(); ++i) {
            int next = graph[here][i];

            if(visited[next]) continue;

            cnt++;
            answer[next] = cnt;
            q.push(next);
            visited[next] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, r; cin >> n >> m >> r;

    for(int i = 0; i < m; ++i) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i <= n; ++i) sort(graph[i].begin(), graph[i].end());

    bfs(r);

    for(int i = 1; i <= n; ++i) cout << answer[i] << '\n';
    
    return 0;
}