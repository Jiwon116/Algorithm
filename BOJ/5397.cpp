#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n; cin >> n;

    while (n--) {
        string s; cin >> s;

        list<char> l;
        list<char>::iterator iter = l.end();
        
        for(auto e : s) {
            if(e == '<'){
                if (iter != l.begin()) iter--;
            }
            else if (e == '>') {
                if (iter != l.end()) iter++;
            }
            else if (e == '-') {
                if (iter != l.begin()) {
                    iter--;
                    iter = l.erase(iter);
                }
            }
            else {
                l.insert(iter, e);
            }
        }

        for(auto e : l) cout << e; cout << '\n';
    }

    return 0;
}