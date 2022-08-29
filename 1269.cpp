#include <iostream>
#include <map>

using namespace std;

map<int, bool> m;

int main() {
    int a, b;
    int num;

	cin >> a >> b;

	for (int i = 0; i < (a + b); ++i) {
		cin >> num;
		if (m[num] == true) // 이미 존재하면 map에서 제거를 한다.
			m.erase(num);
		else // 존재 안하면 추가를 해준다.
			m[num] = true;
	}
	cout << m.size(); // 남은 map 사이즈를 출력

}