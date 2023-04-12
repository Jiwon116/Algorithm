#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[100][100];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	queue<pair<int, int>> moon;
	moon.push(make_pair(0, 0)); //moon.push({0,0});

	while (!moon.empty()) {
		int x = moon.front().first;
		int y = moon.front().second;

		moon.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > n - 1 || nx < 0 || ny < 0 || ny > m - 1) // 범위 맞는지 확인
				continue;
			if (arr[nx][ny] == 1) {
				moon.push(make_pair(nx, ny));
				arr[nx][ny] = arr[x][y] + 1;
			}
		}
	}

	printf("%d\n", arr[n - 1][m - 1]);

	return 0;
}