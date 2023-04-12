#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.rbegin(), v.rend());

    for(auto e : v) cout << e << '\n';

    return 0;
}