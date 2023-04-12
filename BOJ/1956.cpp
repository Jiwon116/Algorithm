#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

// 플로이드 워셜

using namespace std;

int n, m;
int city[401][401]; // city[시작 노드][도착 노드] = 비용

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    // 초기화
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) city[i][j] = 0;
            else city[i][j] = INF;
        }
    }

    for(int i = 0; i < m; ++i) {
        int start, end, value; cin >> start >> end >> value;
        city[start][end] = value;
    }

    // k : 거처가는 노드 / i : 시작 노드 / j : 도착 노드
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }

    int answer = INF;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            answer = min(answer, city[i][j] + city[j][i]);
        }
    }

    if(answer == INF) cout << -1 << '\n';
    else cout << answer << '\n';
    
    return 0;
}