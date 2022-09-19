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
    while(n--){
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    for(auto e : v) cout << e << '\n';

    return 0;
}