#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    unordered_set<string> uos;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;
        uos.insert(s);
    }

    while(m--) {
        string temp; cin >> temp;
        int pos = 0;
        while(pos < temp.length()) {
            string find_s;
            auto it = temp.find(',', pos);
            if(it == temp.npos) {
                find_s = temp.substr(pos);
                if(uos.find(find_s) != uos.end()) uos.erase(find_s);
                break;
            }
            else {
                find_s = temp.substr(pos, it - pos);
                if(uos.find(find_s) != uos.end()) uos.erase(find_s);
                pos = it + 1;
            }
        }

        cout << uos.size() << '\n';
    }
    
    return 0;
}