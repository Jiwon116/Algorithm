#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 87654321

// 플로이드 워셜

using namespace std;

int n, m;
int city[101][101]; // city[시작 노드][도착 노드] = 비용

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    // 처음 - city배열 초기화
    // 시작 노드와 도착 노드가 같은 경우는 본인 노드이므로 0으로 초기화
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) city[i][j] = 0;
            else city[i][j] = INF;
        }
    }

    // 입력으로 들어오는 시작 노드와 도착 노드에 최소 비용 넣기
    for(int i = 0; i < m; ++i) {
        int start, end, value; cin >> start >> end >> value;
        if(city[start][end] > value) city[start][end] = value;
    }

    // k : 거처가는 노드 / i : 시작 노드 / j : 도착 노드
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(city[i][k] + city[k][j] < city[i][j]) city[i][j] = city[i][k] + city[k][j];
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(city[i][j] == INF) cout << 0 << " ";
            else cout << city[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}