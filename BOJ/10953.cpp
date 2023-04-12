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
        char a, b, c; cin >> a >> b >> c;

        cout << a + c - 'a' + 1 << '\n';
    }
    
    return 0;
}