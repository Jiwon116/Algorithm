#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define INF 1e9

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

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (i != j && !adj[i][j])
				adj[i][j] = INF;

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

	int result = 1e9;
	int min_index = -1;

	for (int i = 0; i < n; ++i) {
		int bacon = 0;

		for (int j = 0; j < n; ++j) {
			if (i == j) continue;
			bacon += adj[i][j];
		}

		if (result > bacon) {
			result = bacon;
			min_index = i;
		}
	}

	cout << min_index + 1 << '\n';
	

	return 0;
}