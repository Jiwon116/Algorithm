#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    
    while(true) {
        cin >> n >> m;

        if(!n && !m) break;

        if((n <= m) && (m % n == 0)) cout << "factor\n";
        else if((n >= m) && (n % m == 0)) cout << "multiple\n";
        else cout << "neither\n";
    }
    
    return 0;
}