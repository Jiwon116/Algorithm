#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    set<int> s;
    while(n--) {
        int num; cin >> num;
        s.insert(num);
    }
    
    
    int m; cin >> m;
    while(m--) {
        int f_num; cin >> f_num;
        if(s.find(f_num) != s.end()) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}