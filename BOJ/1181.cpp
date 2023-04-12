#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;

    set< pair<int, string> > word;

    while(n--){
        string s; cin >> s;
        word.insert({s.length(), s});
    }

    for(auto e : word) cout << e.second << '\n';

    return 0;
}