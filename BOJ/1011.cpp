#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

	while(n--) {
		ll from, to; cin >> from >> to;
        
        double dpow = sqrt(to - from);
        int pow = round(sqrt(to - from));

        if(dpow <= pow) cout << pow * 2 - 1 << '\n';
        else cout << pow * 2 << '\n';
	}
    
    return 0;
}