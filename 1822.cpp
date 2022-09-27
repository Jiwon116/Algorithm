#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m; cin >> n >> m;

    set<int> a;
    while(n--) {
        int num; cin >> num;
        a.insert(num);
    }

    while(m--) {
        int f_num; cin >> f_num;
        if(a.find(f_num) != a.end()) a.erase(f_num);
    }

    if(a.size() != 0) {
        cout << a.size() << '\n';
        for(auto e : a) cout << e << " ";
    } else cout << 0;

    cout << '\n';

    return 0;
}