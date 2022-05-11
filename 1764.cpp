#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	
	int n, m, cnt = 0;
	string name;
	set<string> sName;
	set<string> result;

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		// 듣도 못한 사람 입력
		cin >> name;

		// 듣도 못한 사람 저장
		if (i < n) {
			sName.insert(name);
		}
	}

	for (int j = 0; j < m; ++j) {
		// 보도 못한 사람 입력
		cin >> name;

		// 입력받은 보도 못한 사람과 듣도 못한 사람을 비교
		// 같은 값이 있다면 그 사람이 듣도 보도 못한 사람
		if (sName.find(name) != sName.end()) {
			result.insert(name);
			cnt++;
		}
	}

	cout << cnt << endl;

	for (string s : result) {
		cout << s << endl;
	}

	return 0;
}
