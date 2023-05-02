#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
	    int sum = a + b + c + d;

	    if (sum == 0) cout << 'D' << '\n';
	    else if (sum == 1) cout << 'C' << '\n';
	    else if (sum == 2) cout << 'B' << '\n';
	    else if (sum == 3) cout << 'A' << '\n';
	    else cout << 'E' << '\n';
    }
    
    return 0;
}