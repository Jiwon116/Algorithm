#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    set<int> s;
    int n; cin >> n;
    while (n--) {
        int num; cin >> num;
        s.insert(num);
    }

    for(auto e : s) cout << e << ' ';
    cout << '\n';

    return 0;
}