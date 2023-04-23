#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> v(10);
    int sum = 0, res = 0;
    
    for(int i = 0; i < 10; ++i) cin >> v[i];

    for (int i = 0; i < 10; i++) {

		if (abs(100 - sum) >= abs(100 - (sum + v[i]))) sum += v[i];
		else break;
	}
	cout << sum << '\n';

    return 0;
}