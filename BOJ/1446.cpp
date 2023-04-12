#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int m, d;
vector<pii> adj[10001];
int dist[10001];

int dijkstra(int start, int end) {
    fill(dist, dist + 10001, 1e9);

    priority_queue<pii> pq;

    pq.push({0, start});    
    dist[start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(now_cost > dist[now]) continue;

        for(auto e : adj[now]) {
            int next = e.first;
            int next_cost = now_cost + e.second;

            if(next_cost < dist[next]) {
                dist[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }

    return dist[end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> m >> d;

    // 0 -> 1의 거리 값이 1이다
    for(int i = 0; i < d; ++i) adj[i].push_back({i + 1, 1});

    // 문제에서 주어진 거리의 값
    for(int i = 0; i < m; ++i) {
        int from, to, cost; cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }
    
    cout << dijkstra(0, d) << '\n';
    
    return 0;
}