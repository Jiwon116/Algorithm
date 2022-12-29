#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 3e8

using namespace std;

int n, m; // n -> 노드 개수, m -> 간선 개수
int v1, v2; // 반드시 거쳐야 하는 노드
vector<pii> adj[801];  // 연결되어 있는 노드의 정보
int dist[801];   // 최단 거리 테이블

int dijkstra(int start, int end) {

    fill(dist, dist + n + 1, INF); // fill(시작 지점, 끝나는 지점, 초기화 할 값)

    priority_queue<pii> pq;

    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()) {
        int now_cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(now_cost > dist[now]) continue;

        for(int i = 0; i < adj[now].size(); ++i) {
            int next = adj[now][i].first;
            int next_cost = now_cost + adj[now][i].second;

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
    
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int from, to, cost; cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    cin >> v1 >> v2;

    int v1_to_v2 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
    int v2_to_v1 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

    int ans = min(v1_to_v2, v2_to_v1);

    if(ans >= INF) cout << -1 << '\n';
    else cout << ans << '\n';
    
    return 0;
}