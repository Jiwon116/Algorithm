#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int n, m, sum = 0;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for(int i = n; i <= m; ++i) {
        int cnt = 0;

        for(int j = 1; j <= i; ++j) {
            if(i % j == 0) cnt++;
        }

        if(cnt == 2) {
            v.push_back(i);
            sum += i;
        }
    }

    if(!sum) cout << -1 << '\n';
    else cout << sum << '\n' << v[0];

    
    return 0;
}