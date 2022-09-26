#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;
    map<int, int> m;
    while(n--){
        int num; cin >> num;
        if(m.find(num) != m.end()) m[num]++;
        else m[num] = 1;
    }

    int x; cin >> x;
    while(x--) {
        int f_num; cin >> f_num;

        if(m.find(f_num) != m.end()) cout << m[f_num] << " ";
        else cout << 0 << " ";
    }

    cout << '\n';
    
    return 0;
}