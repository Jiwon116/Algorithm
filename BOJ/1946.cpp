#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t, n; cin >> t;

    while(t--) {
        cin >> n;

        vector<pii> v;

        for(int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end());

        int answer = 1, index = 0;

        for(int i = 1; i < n; ++i) {
            if(v[index].second > v[i].second) {
                answer++;
                index = i;
            }
        }

        cout << answer << '\n';
    }
    
    return 0;
}