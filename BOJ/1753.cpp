#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

using namespace std;

int v, e, start;    // v -> 노드 개수, e -> 간선 개수, start -> 시작 노드
vector<pii> adj[100001];  // 연결되어 있는 노드의 정보
int dist[100001];   // 최단 거리 테이블

void dijkstra(int start) {
    priority_queue<pii> pq;

    // 시작 노드로 가는 최단 경로는 0
    pq.push({0, start});    
    dist[start] = 0;

    while (!pq.empty()) {
        int now_cost = -pq.top().first; // 시작 노드에서 현재 노드까지의 거리
        int now = pq.top().second;  // 현재 노드의 번호 (몇 번 노드인지)

        pq.pop();

        if(now_cost > dist[now]) continue;  // 이미 처리된 노드라면 패스

        // 현재 노드와 연결된 노드들을 확인
        for(int i = 0; i < adj[now].size(); ++i) {
            int next = adj[now][i].first; // 다음 노드
            int next_cost = now_cost + adj[now][i].second;   // 다음 노드로 가는 거리

            // 다음 노드로 가는 거리(next_cost)가 원래 거리보다 짧으면 갱신하고 pq에 저장
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
    
    cin >> v >> e >> start;

    // 간선의 개수만큼 노드의 정보를 담음.
    // 양방향 그래프이기 때문에 from과 to 모두 정보를 담아줌
    for(int i = 0; i < e; ++i) {
        int from, to, cost; cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }

    // 최단 거리 테이블 초기화
    // **memset은 INF처럼 큰 수 사용 못함 -> 사용 가능한 수 (-126 ~ 255)
    // fill 함수 사용
    for(int i = 0; i <= v; ++i) {
        dist[i] = INF;
    }

    dijkstra(start);

    for(int i = 1; i <= v; ++i) {
        if(dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    
    return 0;
}