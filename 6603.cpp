// #include <iostream>

// using namespace std;

// 조합으로 풀어도 가능 (어차피 c++에서는 조합이 백트래킹으로 구현됨)

// int n;
// int s[14];
// int ans[6];

// void dfs(int start, int depth) {

// 	if (depth == 6) {
// 		for (int i = 0; i < 6; i++) {
// 			cout << ans[i] << " ";
// 		}
// 		cout << endl;
// 		return;
// 	}

// 	for (int i = start; i < n; i++) {
// 		ans[depth] = s[i];
// 		dfs(i + 1, depth+1);
// 	}

// }

// int main() {

// 	while (cin >> n && n) {
// 		for (int i = 0; i < n; i++) {
// 			cin >> s[i];
// 		}

// 		dfs(0, 0);

// 		cout << endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main() {

	while(true) {
		cin >> n;
		if (n == 0) break;

		v.clear();
		v.resize(n, 0); // n만큼 크기를 새로 지정하고 각각 0으로 초기화

		vector<int> mask(n, 0);
		for (int i = 0; i < 6; ++i) mask[i] = 1;

		// for (int i = 0; i < n; ++i) cin >> v[i];
		for (int &e : v) cin >> e;
		
		do {
			for (int i = 0; i < n; ++i) {
				if (mask[i] == 1) {
					cout << v[i] << " ";
				}
			}

			cout << "\n";

		} while (prev_permutation(mask.begin(), mask.end()));

		cout << "\n";
	}

	return 0;
}
