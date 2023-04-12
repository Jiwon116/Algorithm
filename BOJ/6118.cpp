#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m;
vector<int> v[50001];
bool visited[50001] = {false, };
int max_dis = -1;
vector<int> max_node;

// 큐에 어떤 정보가 들어가야 하냐
// 1. 현재 정점의 노드
// 2. root부터 현재 정점까지의 거리
void bfs(int cur) {
    queue<pii> q;
    q.push({cur, 0});
    visited[cur] = true;

    while(!q.empty()) {
        pii x = q.front();
        q.pop();

        if(x.second > max_dis) {
            max_dis = x.second;
            max_node.clear();
            max_node.push_back(x.first);
        } else if (x.second == max_dis) {
            max_node.push_back(x.first);
        }

        for(auto e : v[x.first]) {
            if(visited[e]) continue;

            visited[e] = true;
            q.push({e, x.second + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int first, second; cin >> first >> second;
        v[first].push_back(second); // v[1] = {2, 3}
        v[second].push_back(first);
    }

    bfs(1);

    cout << *min_element(max_node.begin(), max_node.end()) << " " << max_dis << " " << max_node.size() << '\n';
    
    return 0;
}