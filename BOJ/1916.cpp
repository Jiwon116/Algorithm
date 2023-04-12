#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int n, m; // n -> 노드 개수, m -> 간선 개수
int start_node, end_node; // start -> 시작 노드, end -> 끝 노드
vector<pii> adj[100001];  // 연결되어 있는 노드의 정보
int dist[100001];   // 최단 거리 테이블

void dijkstra(int start) {
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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int from, to, cost; cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }

    fill(dist + 1, dist + n + 1, INF); // fill(시작 지점, 끝나는 지점, 초기화 할 값)

    cin >> start_node >> end_node;

    dijkstra(start_node);

    cout << dist[end_node] << '\n';
    
    return 0;
}