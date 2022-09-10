#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;


    vector<int> v;

    for(int i = 0; i < n; ++i) {
        int p; cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());

    int result = 0;
    for(int i = 0; i < n; ++i) {
        result += v[i] * (n - i);
    }

    cout << result << '\n';

    return 0;
}