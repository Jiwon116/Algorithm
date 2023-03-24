#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int a, b, c; cin >> a >> b >> c;

    cout << ((b / a) * 3) * c << '\n';
    
    return 0;
}