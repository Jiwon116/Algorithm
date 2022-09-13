#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {

    int n; cin >> n;

    map<string, int> m;

    for(int i = 0; i < n; ++i) {
        string name; cin >> name;
        
        if (m.find(name) != m.end()) m[name] += 1;
        else m[name] = 1;
    }

    string answer = "";
    int max_count = 0;
    for(auto e = m.begin(); e != m.end(); ++e) {
        if (max_count < (e -> second)) {
            max_count = (e -> second);
            answer = (e -> first);
        } else if (max_count == (e -> second)) {
            if ((e -> first) < answer) answer = (e -> first);
        }
    }

    cout << answer << '\n';

    return 0;
}
