#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    vector<int> v;
    while(n--) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int m; cin >> m;
    while(m--) {
        int f_num; cin >> f_num;
        cout << binary_search(v.begin(), v.end(), f_num) << " ";
    }

    cout << '\n';

    return 0;
}