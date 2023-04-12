#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int &e : A) cin >> e;

    vector<int> LIS;
    LIS.push_back(-2e9);

    for (int e : A) {
        if (LIS.back() < e) LIS.push_back(e);
        else {
            auto it = lower_bound(LIS.begin(), LIS.end(), e);
            *it = e;
        }
    }

    cout << LIS.size() - 1 << "\n";

    return 0;
}