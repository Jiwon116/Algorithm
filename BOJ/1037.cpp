#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int num; cin >> num;
	vector<int> v(num);

	for (int i = 0; i < num; i++) {
		cin >> v[i];
	}

    // 정렬 후 가장 첫번째 원소와 마지막 원소를 곱한 값
	sort(v.begin(), v.end());

	cout << v[0] * v[v.size() - 1] << "\n";

	return 0;
}