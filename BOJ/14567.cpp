#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

// 위상 정렬

using namespace std;

int n, m;
vector<int> graph[1001];
int inDegree[1001];
int answer[1001];

void topology() {
    queue<int> q;

    for(int i = 1; i <= n; ++i) {
        if(!inDegree[i]) {
            q.push(i);
            answer[i] = 1;
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int there : graph[cur]) {
            inDegree[there]--;

            if(!inDegree[there]) {
                q.push(there);
                answer[there] = max(answer[there], answer[cur] + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    memset(answer, 0, sizeof(answer));
    
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
        inDegree[to]++;
    }

    topology();

    for(int i = 1; i <= n; ++i) cout << answer[i] << " "; cout << '\n';
    
    return 0;
}