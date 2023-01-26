#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

// 최소 스패닝 트리 - 프림 알고리즘 O(n^2)

int v, e;
vector<pii> graph[10001];
bool visited[10001];

int prim() {
    priority_queue<pii> pq;
    int result = 0;

    pq.push({-0, 1});

    while(!pq.empty()) {
        int now_cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if(visited[now]) continue; // 방문했으면 넘어가기

        result += now_cost; // 가중치 더하기
        visited[now] = true; // 방문처리

        for(int i = 0; i < graph[now].size(); ++i) {
            int next = graph[now][i].first;
            int next_cost = graph[now][i].second;
            pq.push({-next_cost, next});
        }

    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    memset(visited, false, sizeof(visited));

    cin >> v >> e;

    for(int i = 0; i < e; ++i) {
        int from, to ,cost; cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }

    cout << prim();
    
    return 0;
}