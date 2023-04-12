#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int n, m, k, start;
vector<pii> adj[300001];
int dist[300001];
vector<int> ans;

void dijkstra(int start) {
    fill(dist, dist + 300001, 1e9);

    priority_queue<pii> pq;

    pq.push({0, start});    
    dist[start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(now_cost > dist[now]) continue;
        if(now_cost == k) ans.push_back(now);

        // 현재 노드와 연결된 노드들을 확인
        for(int i = 0; i < adj[now].size(); ++i) {
            int next = adj[now][i].first;
            int next_cost = now_cost + adj[now][i].second;

            if(next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> k >> start;

    for(int i = 0; i < m; ++i) {
        int from, to; cin >> from >> to;
        adj[from].push_back({to, 1});
    }
    
    dijkstra(start);

    sort(ans.begin(), ans.end());

    if(ans.empty()) cout << -1 << '\n';
    else for(auto e : ans) cout << e << '\n';
    
    return 0;
}