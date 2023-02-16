#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cout << 100 << '\n';

    for(int i = 1; i <= 100; ++i) {
        for(int j = 1; j <= 100; ++j) {
            if(i == j) cout << 0 << " ";
            else if(i == 100 || j == 100) cout << 1 << " "; // d(i, 100) = 1, d(100, j) = 1
            else cout << 3 << " "; // d(i, 100) + d(100, j)보다 항상 커야함 -> 1 + 1인 2보다 커야함
        }

        cout << '\n';
    }
    
    return 0;
}