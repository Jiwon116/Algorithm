#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

// 플로이드 워셜

using namespace std;

int n;
int graph[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }

    // k : 거처가는 노드 / i : 시작 노드 / j : 도착 노드
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(graph[i][k] && graph[k][j]) graph[i][j] = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}