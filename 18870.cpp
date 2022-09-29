#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    vector<int> v1;
    vector<int> v2;

    while(n--) {
        int num; cin >> num;
        v1.push_back(num);
        v2.push_back(num);
    }

    sort(v2.begin(), v2.end());

    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for(auto e : v1) {
        cout << lower_bound(v2.begin(), v2.end(), e) - v2.begin() << " ";
    }

    cout << '\n';

    return 0;
}