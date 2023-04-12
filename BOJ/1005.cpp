#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

// 위상 정렬

int t, n, m, end_node; // t는 테스트 케이스, n은 정점 개수, m은 간선 개수, end는 끝나는 노드
int inDegree[1001];
vector<int> graph[1001];
int cost[1001];
int answer[1001];

int topology() {
    queue<pii> q;

    for(int i = 1; i <= n; ++i) {
        if(!inDegree[i]) {
            q.push({i, cost[i]});
        }
    }

    while(!q.empty()) {
        int cur = q.front().first;
        int start_time = q.front().second;

        q.pop();

        if(cur == end_node) return start_time;

        for(int there : graph[cur]) {
            inDegree[there]--;
            answer[there] = max(answer[there], start_time + cost[there]);

            if(!inDegree[there]) 
                q.push({there, answer[there]});
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> t;

    while(t--) {
        // 초기화
        memset(inDegree, 0, sizeof(inDegree));
        memset(answer, 0, sizeof(answer));
        for(int i = 0; i <= 1000; ++i) graph[i].clear();

        cin >> n >> m;

        for(int i = 1; i <= n; ++i) cin >> cost[i]; // 건설 완료 시간

        for(int i = 0; i < m; ++i) {
            int from, to; cin >> from >> to;
            graph[from].push_back(to);
            inDegree[to]++;
        }

        cin >> end_node;

        cout << topology() << '\n';
    }
    
    return 0;
}