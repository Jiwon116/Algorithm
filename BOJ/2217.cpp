#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) cin >> v[i];
    
    sort(v.begin(), v.end());

    int answer = 0;

    for(int i = 0; i < n; ++i) {
        if(answer < v[i] * (n - i)) answer = v[i] * (n - i);
    }

    cout << answer << '\n';
    
    return 0;
}