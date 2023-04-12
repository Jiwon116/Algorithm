#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> v(3);

    for(int i = 0; i < 3; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cout << v[1] << '\n';
    
    return 0;
}