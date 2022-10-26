#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > v;
vector<int> LIS;

int main() {
    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    LIS.push_back(-1);

    for(auto e : v) {
        if(LIS.back() < e.second) LIS.push_back(e.second);
        else {
            auto it = lower_bound(LIS.begin(), LIS.end(), e.second);
            *it = e.second; 
        }
    }
    
    cout << n - (LIS.size() - 1) << '\n';

    return 0;
}