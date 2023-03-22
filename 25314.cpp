#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    for(int i = 0; i < n / 4; ++i) {
        cout << "long ";
        if(i == n / 4 - 1) cout << "int\n";
    }
    
    return 0;
}