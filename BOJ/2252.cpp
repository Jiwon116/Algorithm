#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

// 위상 정렬

int n, m; // n은 정점의 개수, m은 간선의 개수
int inDegree[32001]; // 각 정점에 꽂히는 간선의 개수 (내차수)
vector<int> graph[32001]; // 간선 정보
vector<int> answer; // 줄 세운 정보

void topology() {
    queue<int> q;

    for(int i = 1; i <= n; ++i) {
        if(!inDegree[i]) q.push(i);
    }

    for(int i = 1; i <= n; ++i) {
        if(q.empty()) return;

        int cur = q.front();

        q.pop();
        
        answer.push_back(cur);

        for(int j = 0; j < graph[cur].size(); ++j) {
            int next = graph[cur][j];
            if(--inDegree[next] == 0) q.push(next);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        inDegree[to]++;
    }

    topology();

    for(auto e : answer) cout << e << " "; cout << '\n';
    
    return 0;
}