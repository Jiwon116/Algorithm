#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    while(true) {
        int n; cin >> n;

        if(!n) break;

        int block = 0;

        for(int i = 1; i <= n; ++i) block += i;

        cout << block << '\n';
    }
    
    return 0;
}