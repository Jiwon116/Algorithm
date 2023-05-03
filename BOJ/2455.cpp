#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, total = 0, answer = 0;

    for(int i = 0; i < 4; ++i) {
        cin >> n >> m;
        total += m - n;

        answer = max(answer, total);
    }

    cout << answer << '\n';
    
    return 0;
}