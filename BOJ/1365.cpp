#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    vector<int> LIS;
    LIS.push_back(-1);

    for(auto e : v) {
        if(LIS.back() < e) LIS.push_back(e);
        else {
            auto it = lower_bound(LIS.begin(), LIS.end(), e);
            *it = e;
        }
    }

    cout << n - (LIS.size() - 1) << '\n';

    return 0;
}