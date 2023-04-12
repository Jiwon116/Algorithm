#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#define MAX 101

using namespace std;

int n; //컴퓨터의 수
int m; //연결되어 있는 컴퓨터의 쌍
vector<int> adj[MAX];
bool visited[MAX];

int bfs(int x){
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(x);
    visited[x] = true;

    int count = 0;

    while(!q.empty()) {
        int here = q.front();
        q.pop(); ++count;

        for (int there : adj[here]) {
            if(!visited[there]) {
                visited[there] = true;
                q.push(there);
            }
        }
    }

    return count;
}

int main() {
    cin >> n;
    cin >> m;

    for(int i = 0; i<m; ++i) {
        int from, to = 0;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    cout << bfs(1) - 1 << "\n";

    return 0;
}