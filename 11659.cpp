#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    vector<int> prefix_sum(n);

    prefix_sum[0] = v[0];
    for(int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + v[i];
    }

    while(m--) {
        int i, j; cin >> i >> j;

        if(i == 1) cout << prefix_sum[j - 1] << '\n';
        else cout << prefix_sum[j - 1] - prefix_sum[i - 2] << '\n';
    }

    return 0;
}