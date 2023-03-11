#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

// 플로이드 워셜

using namespace std;

int n, m;
int adj[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> n >> m;

	for(int i = 0; i < m; ++i) {
		int from, to; cin >> from >> to;
		adj[from][to] = 1;
		adj[to][from] = 1;
	}

    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if (i == j) continue;
                else if(adj[i][k] && adj[k][j]) {
                    if (adj[i][j] == 0) adj[i][j] = adj[i][k] + adj[k][j];
                    else adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }

	int result = 1e9;
	int answer;

	for (int i = 1; i <= n; ++i) {
		int bacon = 0;

		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			bacon += adj[i][j];
		}

		if (result > bacon) {
			result = bacon;
			answer = i;
		}
	}

	cout << answer << '\n';
	

	return 0;
}