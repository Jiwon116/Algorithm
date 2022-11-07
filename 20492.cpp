#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    cout << n - (int)(n * 0.22) << " " << n - (int)((n * 0.2) * 0.22);
    
    return 0;
}