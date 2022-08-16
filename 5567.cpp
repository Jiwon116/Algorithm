#include <iostream>
#include <string.h>
#include <queue>
#define MAX 10001

using namespace std;

// 양방향 or 무방향 그래프 탐색(dfs, bfs, 백트래킹으로 구현 가능)
// 깊이가 2까지인 노드의 개수를 구하기
// 입력에 같은 간선이 들어올 수 있음 (ex) 1 - 2 / 2 - 1)
// bfs로 구현하는 것이 좋음

vector<int> vec[MAX];
bool visited[MAX];
int count = 0;

void bfs(int start) {

    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q; // first: node, depth
    q.push({start, 0});
    visited[start] = true;
    
    if (vec[1].size() == 0) return;

    while(!q.empty()) {
        int here = q.front().first;
        int dep = q.front().second;
        count += 1;
        q.pop();

        for (int i : vec[here]) {
            if (visited[i] == false && dep + 1 <= 2) {
                q.push({i, dep + 1});
                visited[i] = true;
            }
        }
    }

    count -= 1;
}

int main() {

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        vec[to].push_back(from);
    }

    bfs(1);

    cout << count << "\n";

    return 0;
}
